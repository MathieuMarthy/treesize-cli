#pragma once

#include <string>

#include "fileModel.hpp"

constexpr int UNLIMITED_DEPTH = -1;

std::string getFileString(const FileModel &file);

void display(const FileModel &file, int currentDepth, int maxDepth, const bool showOnlyDirectory);

void displaySortedList(const FileModel &file, const bool showOnlyDirectory);
