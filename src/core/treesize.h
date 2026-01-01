#pragma once

#include <vector>
#include "fileModel.h"

class Treesize
{
public:
    static FileModel getDirectorySize(const std::string &path, int depth);

private:
    static void scanDirectory(FileModel &parentDirectory, int currentDepth, int maxDepth);
};
