#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "CLI/CLI.hpp"

#include "treesize.hpp"
#include "display.hpp"

int main(int argc, char **argv)
{
    CLI::App app{"treesize-cli description"};

    std::string path;
    int depth;
    bool showOnlyDirectory;
    app.add_option("path", path, "directory to scan")
        ->required();
    app.add_option("-d,--depth", depth, "depth of directory tree to display")
        ->default_val(-1);
    app.add_flag("-o,--only-directory", showOnlyDirectory)
        ->default_val(false);

    CLI11_PARSE(app, argc, argv);

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Set the console to UTF-8.
#endif

    FileModel rootDir = Treesize::getDirectorySize(path);
    std::cout << "Total size of the directory: " << rootDir.getTotalSize() << std::endl;
    display(rootDir, 0, depth, showOnlyDirectory);

    return 0;
}
