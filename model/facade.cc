#include "facade.h"
#include "list.h"
#include "text_file_handler.h"

bool UpperCaseFacade::ReadFile(const std::string &file_path) {
  TextFileHandler handler(file_path);
  LinkedList<std::string> content = handler.ReadFile();
  content_ = content;
  content_.Display();
  return true;
}

bool UpperCaseFacade::Handlefile() {
  content_.Sort();
  content_.Display();
  return true;
}

bool UpperCaseFacade::WriteFile(std::string &filename) const {
  TextFileHandler handler(filename);
  //  handler.Writefile();
  std::cout << "handler opened" << std::endl;
}
