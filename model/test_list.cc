#include "list.h"
#include <string>
#include "facade.h"
#include "text_file_handler.h"

int main() {
    UpperCaseFacade facade;
    facade.HandleFile("file_1.txt");
}