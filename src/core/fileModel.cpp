#include "fileModel.h"
#include <iostream>

size_t FileModel::getTotalSize() const
{
    size_t childsSize = 0;

    for (const FileModel &child : childs)
    {
        childsSize += child.getTotalSize();
    }

    return childsSize + size;
}
