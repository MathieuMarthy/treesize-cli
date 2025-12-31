#include "fileModel.h"
#include <iostream>

int FileModel::getTotalSize()
{
    long childs_size = 0;

    for (FileModel &child : childs)
    {
        childs_size += child.getTotalSize();
    }

    return childs_size + size;
}
