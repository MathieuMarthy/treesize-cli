#include "treesize.h"
#include "fileModel.h"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileModel Treesize::getDirectorySize(const std::string &path)
{
    FileModel *rootDir = new FileModel(path);

    Treesize::scanDirectory(*rootDir);

    return *rootDir;
}

void Treesize::scanDirectory(FileModel &parentDirectory)
{
    for (const auto &entry : fs::directory_iterator(parentDirectory.path))
    {
        if (entry.is_symlink())
        {
            continue;
        }

        // attach the file to his parent
        FileModel *file = new FileModel(entry.path().string());
        parentDirectory.childs.push_back(*file);
        std::cout << file->path << std::endl;

        if (entry.is_directory())
        {
            // recursive call
            Treesize::scanDirectory(*file);
        }
        else
        {
            file->size = entry.file_size();
        }
    }
}
