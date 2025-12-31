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

    Treesize::getDirectorySize(argv[1]);

    return 0;
}
