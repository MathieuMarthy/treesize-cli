#include "fileModel.hpp"
#include <iostream>

size_t FileModel::getTotalSize(const bool useCache) const
{
    if (useCache && this->cachedTotalSize.has_value())
    {
        return this->cachedTotalSize.value();
    }

    size_t totalChildrenSize = 0;

    for (const FileModel &child : this->children)
    {
        totalChildrenSize += child.getTotalSize();
    }

    size_t totalSize = totalChildrenSize + this->size;

    if (useCache)
    {
        this->cachedTotalSize = totalSize;
    }

    return totalSize;
}

void FileModel::getAllFilesRecursively(std::vector<const FileModel *> &allFiles) const
{
    allFiles.push_back(this);

    for (const auto &child : this->children)
    {
        child.getAllFilesRecursively(allFiles);
    }
}
