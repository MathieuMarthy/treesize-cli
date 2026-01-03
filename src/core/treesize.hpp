#pragma once

#include <vector>
#include "fileModel.hpp"

class Treesize
{
public:
    static FileModel getDirectorySize(const std::string &path);

private:
    static void scanDirectory(FileModel &parentDirectory);
};
