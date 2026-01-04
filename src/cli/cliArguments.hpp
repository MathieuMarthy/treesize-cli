#pragma once
#include <string>

constexpr int UNLIMITED_DEPTH = -1;

struct CliArguments
{
    std::string path;
    int depth = UNLIMITED_DEPTH;
    bool showOnlyDirectory = false;
    bool showOnlyFiles = false;
    bool displayAsSortedList = false;
};
