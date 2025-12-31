#include <iostream>
#include "treesize.h"

void printUsage()
{
    std::cerr << "Usage: treesize-cli <directory>" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printUsage();
        return 1;
    }

    FileModel dir = Treesize::getDirectorySize(argv[1]);
    std::cout << "Total size of the directory: " << dir.getTotalSize() << std::endl;

    return 0;
}
