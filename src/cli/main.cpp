#include <iostream>
#include <format>
#include "treesize.h"
#include "CLI/CLI.hpp"

std::string getFileSizeString(size_t fileSize)
{
    uint8_t suffixIndex = 0;
    float size = fileSize;

    while (size > 1024 && cpt < 4)
    {
        suffixIndex++;
        size /= 1024;
    }

    static const char *suffix[] = {"o", "Ko", "Mo", "Go", "To"};
    return std::format("{:.2f}", size) + ' ' + suffix[suffixIndex];
}

void display(const FileModel &file, int currentDepth, int maxDepth)
{
    if (maxDepth != -1 && currentDepth > maxDepth)
    {
        return;
    }

    std::cout << std::string(currentDepth * 2, ' ') << file.path << " - " << getFileSizeString(file.getTotalSize()) << std::endl;

    for (const auto &child : file.childs)
    {
        display(child, currentDepth + 1, maxDepth);
    }
}

int main(int argc, char **argv)
{
    CLI::App app{"treesize-cli description"};

    std::string path;
    int depth;
    app.add_option("path", path, "directory to scan")
        ->required();
    app.add_option("-d,--depth", depth, "depth of directory tree to display")
        ->default_val(-1);

    CLI11_PARSE(app, argc, argv);

    FileModel rootDir = Treesize::getDirectorySize(path);
    std::cout << "Total size of the directory: " << rootDir.getTotalSize() << std::endl;
    display(rootDir, 0, depth);

    return 0;
}
