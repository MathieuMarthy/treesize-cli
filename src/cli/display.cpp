#include <string>
#include <format>
#include <iostream>

#include "display.hpp"
#include "fileModel.hpp"

const char *suffix[] = {"o", "Ko", "Mo", "Go", "To"};

std::string getFileString(const FileModel &file)
{
    uint8_t suffixIndex = 0;
    float size = file.getTotalSize();

    while (size > 1024 && suffixIndex < 4)
    {
        suffixIndex++;
        size /= 1024;
    }

    return std::format(
        "{} - {} {:.2f} {}",
        (file.isDirectory) ? "📂" : "📄",
        file.path,
        size,
        suffix[suffixIndex]);
}

void display(const FileModel &file, int currentDepth, const int maxDepth, const bool showOnlyDirectory)
{
    if (maxDepth != UNLIMITED_DEPTH && currentDepth > maxDepth)
    {
        return;
    }

    if (!showOnlyDirectory || file.isDirectory)
    {
        std::cout << std::string(currentDepth * 4, ' ') << getFileString(file) << std::endl;
    }

    for (const auto &child : file.children)
    {
        display(child, currentDepth + 1, maxDepth, showOnlyDirectory);
    }
}

void displaySortedList(const FileModel &file, const bool showOnlyDirectory)
{
    std::vector<const FileModel *> allFiles;
    file.getAllFilesRecursively(allFiles);

    std::sort(allFiles.begin(), allFiles.end(), [](const FileModel *a, const FileModel *b)
              { return a->getTotalSize() > b->getTotalSize(); });

    for (const auto &f : allFiles)
    {
        if (showOnlyDirectory && !f->isDirectory)
        {
            continue;
        }

        std::cout << getFileString(*f) << std::endl;
    }
}
