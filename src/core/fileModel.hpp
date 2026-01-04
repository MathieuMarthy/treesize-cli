#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <optional>

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
    mutable std::optional<size_t> cachedTotalSize;

    size_t getTotalSize(const bool useCache = true) const;
    void getAllFilesRecursively(std::vector<const FileModel *> &allFiles) const;
};
