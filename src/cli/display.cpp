#include <string>
#include <format>
#include <iostream>

#include "display.hpp"
#include "fileModel.hpp"

const char *suffix[] = {"o", "Ko", "Mo", "Go", "To"};

std::string getFileString(const FileModel &file)
{
    uint8_t suffixIndex = 0;
    float size = file.getTotalSize();

    while (size > 1024 && suffixIndex < 4)
    {
        suffixIndex++;
        size /= 1024;
    }

    return std::format(
        "{} - {} {:.2f} {}",
        (file.isDirectory) ? "📂" : "📄",
        file.path,
        size,
        suffix[suffixIndex]);
}

void display(const FileModel &file, int currentDepth, const CliArguments &cliArgs)
{
    if (cliArgs.depth != UNLIMITED_DEPTH && currentDepth > cliArgs.depth)
    {
        return;
    }

    if ((!file.isDirectory && !cliArgs.showOnlyDirectory) || (file.isDirectory && !cliArgs.showOnlyFiles))
    {
        std::cout << std::string(currentDepth * 4, ' ') << getFileString(file) << std::endl;
    }

    for (const auto &child : file.children)
    {
        display(child, currentDepth + 1, cliArgs);
    }
}

void displaySortedList(const FileModel &file, const CliArguments &cliArgs)
{
    std::vector<const FileModel *> allFiles;
    file.getAllFilesRecursively(allFiles);

    std::sort(allFiles.begin(), allFiles.end(), [](const FileModel *a, const FileModel *b)
              { return a->getTotalSize() > b->getTotalSize(); });

    for (const auto &f : allFiles)
    {
        if ((!f->isDirectory && !cliArgs.showOnlyDirectory) || (f->isDirectory && !cliArgs.showOnlyFiles))
        {
            std::cout << getFileString(*f) << std::endl;
        }
    }
}
