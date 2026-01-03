#pragma once

#include <string>

#include "fileModel.hpp"

std::string getFileString(const FileModel &file);

void display(const FileModel &file, int currentDepth, int maxDepth, const bool showOnlyDirectory);
