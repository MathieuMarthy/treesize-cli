#include "treesize.hpp"
#include "fileModel.hpp"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

FileModel Treesize::getDirectorySize(const std::string &path)
{
    FileModel rootDir(path, true);

    Treesize::scanDirectory(rootDir);

    return rootDir;
}

void Treesize::scanDirectory(FileModel &parentDirectory)
{
    for (const auto &entry : fs::directory_iterator(parentDirectory.path))
    {
        if (entry.is_symlink())
        {
            continue;
        }

        // attach the file to its parent
        parentDirectory.children.emplace_back(entry.path().string(), entry.is_directory());
        FileModel &file = parentDirectory.children.back();

        if (entry.is_directory())
        {
            // recursive call
            Treesize::scanDirectory(file);
        }
        else
        {
            file.size = entry.file_size();
        }
    }
}
