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
    uintmax_t size = 0;
    std::vector<FileModel> childs = std::vector<FileModel>();

    int getTotalSize();
};
