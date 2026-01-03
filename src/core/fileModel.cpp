#include "fileModel.hpp"
#include <iostream>

size_t FileModel::getTotalSize() const
{
    size_t childsSize = 0;

    for (const FileModel &child : this->children)
    {
        childsSize += child.getTotalSize();
    }

    return childsSize + this->size;
}
