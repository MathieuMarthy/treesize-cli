#pragma once

#include <string>
#include <vector>
#include <cstdint>

class FileModel
{
public:
    FileModel(const std::string filePath, const bool isDirectory)
    {
        this->path = filePath;
        this->isDirectory = isDirectory;
    }

    std::string path;
    bool isDirectory;
    size_t size = 0;
    std::vector<FileModel> children;

    size_t getTotalSize() const;
};
