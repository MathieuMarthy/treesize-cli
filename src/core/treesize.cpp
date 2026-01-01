#include "treesize.h"
#include "fileModel.h"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileModel Treesize::getDirectorySize(const std::string &path, int depth)
{
    FileModel rootDir(path);

    Treesize::scanDirectory(rootDir);

    return rootDir;
}

void Treesize::scanDirectory(FileModel &parentDirectory, int currentDepth, int maxDepth)
{
    for (const auto &entry : fs::directory_iterator(parentDirectory.path))
    {
        if (entry.is_symlink())
        {
            continue;
        }

        // attach the file to his parent
        parentDirectory.childs.emplace_back(entry.path().string());
        FileModel &file = parentDirectory.childs.back();

        if (entry.is_directory() && (maxDepth == -1 || currentDepth < maxDepth))
        {
            // recursive call
            Treesize::scanDirectory(file, currentDepth + 1, maxDepth);
        }
        else
        {
            file.size = entry.file_size();
        }
    }
}
