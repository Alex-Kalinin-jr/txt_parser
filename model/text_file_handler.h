#ifndef THIS_PROJECT_HANDLER_H
#define THIS_PROJECT_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include "list.h"

class TextFileHandler {
public:
    TextFileHandler(const std::string& path) : file_path(path) {}

    LinkedList<std::string> ReadFile();

    // void WriteFile(const LinkedList<std::string> &);

private:
    std::string file_path;
};

#endif // THIS_PROJECT_HANDLER_H