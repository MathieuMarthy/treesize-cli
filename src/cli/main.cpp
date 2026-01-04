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
    int depth = UNLIMITED_DEPTH;
    bool showOnlyDirectory = false;
    bool displayAsSortedList = false;
    app.add_option("path", path, "directory to scan")
        ->required();
    app.add_option("-d,--depth", depth, "depth of directory tree to display");
    app.add_flag("-o,--only-directory", showOnlyDirectory, "show only directories");
    app.add_flag("-l,--list", displayAsSortedList, "display as sorted list");

    CLI11_PARSE(app, argc, argv);

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Set the console to UTF-8.
#endif


    FileModel rootDir = Treesize::getDirectorySize(path);
    std::cout << "Total size of the directory: " << rootDir.getTotalSize() << std::endl;

    if (displayAsSortedList)
    {
        displaySortedList(rootDir, showOnlyDirectory);
    }
    else
    {
        display(rootDir, 0, depth, showOnlyDirectory);
    }

    return 0;
}
