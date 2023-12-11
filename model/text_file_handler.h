#ifndef THIS_PROJECT_HANDLER_H
#define THIS_PROJECT_HANDLER_H

#include "list.h"
#include <fstream>
#include <iostream>
#include <string>

class TextFileHandler {
public:
  TextFileHandler(const std::string path) : file_path(path) {}

  LinkedList<std::string> ReadFile();

  void WriteFile(const LinkedList<std::pair<std::string, int>> &content);

private:
  std::string file_path;
};

#endif // THIS_PROJECT_HANDLER_H
