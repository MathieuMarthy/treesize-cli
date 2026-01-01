#pragma once

#include <string>
#include <vector>
#include <cstdint>

class FileModel
{
public:
    FileModel(const std::string filePath)
    {
        path = filePath;
    }

    std::string path;
    size_t size = 0;
    std::vector<FileModel> childs = std::vector<FileModel>();

    size_t getTotalSize() const;
};
