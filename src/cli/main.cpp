#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

#include "CLI/CLI.hpp"

#include "treesize.hpp"
#include "display.hpp"
#include "cliArguments.hpp"

int main(int argc, char **argv)
{
    CLI::App app{"treesize-cli description"};

    CliArguments cliArgs;

    app.add_option("path", cliArgs.path, "directory to scan")
        ->required();
    app.add_option("-d,--depth", cliArgs.depth, "depth of directory tree to display");
    app.add_flag("-D,--directories-only", cliArgs.showOnlyDirectory, "show only directories");
    app.add_flag("-F,--files-only", cliArgs.showOnlyFiles, "show only files");
    app.add_flag("-l,--list", cliArgs.displayAsSortedList, "display as sorted list");

    CLI11_PARSE(app, argc, argv);

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // Set the console to UTF-8.
#endif

    if (cliArgs.showOnlyDirectory && cliArgs.showOnlyFiles)
    {
        std::cerr << "Cannot use --directories-only and --files-only at the same time." << std::endl;
        return 1;
    }

    FileModel rootDir = Treesize::getDirectorySize(cliArgs.path);
    std::cout << "Total size of the directory: " << getDisplaybleFileSize(rootDir.getTotalSize()) << std::endl;

    if (cliArgs.displayAsSortedList)
    {
        displaySortedList(rootDir, cliArgs);
    }
    else
    {
        display(rootDir, 0, cliArgs);
    }

    return 0;
}
