#pragma once

#include <string>

#include "fileModel.hpp"

std::string getFileSizeString(const FileModel &file);

void display(const FileModel &file, int currentDepth, int maxDepth);
