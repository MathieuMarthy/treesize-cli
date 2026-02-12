#pragma once

#include <string>

#include "fileModel.hpp"
#include "cliArguments.hpp"

std::string getDisplaybleFileSize(const float fileSize);

std::string getFileString(const FileModel &file);

void display(const FileModel &file, int currentDepth, const CliArguments &cliArgs);

void displaySortedList(const FileModel &file, const CliArguments &cliArgs);
