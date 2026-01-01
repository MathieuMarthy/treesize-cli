#include <iostream>
#include "treesize.h"
#include "CLI/CLI.hpp"

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

    std::cout << "depth: " << depth << ", path: " << path << std::endl;

    FileModel rootDir = Treesize::getDirectorySize(path, depth);
    std::cout << "Total size of the directory: " << rootDir.getTotalSize() << std::endl;

    return 0;
}
