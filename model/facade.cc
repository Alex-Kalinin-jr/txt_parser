#include "facade.h"
#include "list.h"
#include "text_file_handler.h"

bool UpperCaseFacade::HandleFile(const std::string& file_path) {
    TextFileHandler handler(file_path);
    LinkedList<std::string> content = handler.ReadFile();
    content.Sort();
    content.Display();
    return true;
}