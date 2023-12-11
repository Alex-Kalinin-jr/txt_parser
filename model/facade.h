#ifndef THIS_PROJECT_FACADE_H
#define THIS_PROJECT_FACADE_H

#include "list.h"
#include "text_file_handler.h"

class UpperCaseFacade {
public:
  UpperCaseFacade() {}
  bool ReadFile(const std::string &file_path);
  bool Handlefile();
  bool WriteFile(std::string &filename) const;

private:
  LinkedList<std::string> content_;
  LinkedList<std::pair<std::string, int>> sorted_content_;
};

#endif // THIS_PROJECT_FACADE_H
