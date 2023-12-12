#include "facade.h"
#include "list.h"
#include "text_file_handler.h"

bool UpperCaseFacade::ReadFile(const std::string &file_path) {
  TextFileHandler handler(file_path);
  content_ = handler.ReadFile();
  return true;
}

bool UpperCaseFacade::Handlefile() {
  sorted_content_ = content_.DoubleCriteriaSort();
  return true;
}

bool UpperCaseFacade::WriteFile(std::string &filename) const {
  TextFileHandler handler(filename);
  handler.WriteFile(sorted_content_);
}

//| - content_: LinkedList<std::string> |
//| - sorted_content_: LinkedList<std::pair<std::string, int>> |
//+-------------------------------------+
//| + UpperCaseFacade()                  |
//| + ReadFile(const std::string&): bool |
//| + HandleFile(): bool                 |
//| + WriteFile(std::string&): bool      |
