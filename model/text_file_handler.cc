#include "text_file_handler.h"

#include <iostream>

#include "list.h"

LinkedList<std::string> TextFileHandler::ReadFile() {
    std::ifstream file(file_path);
    LinkedList<std::string> content;

    if (file.is_open()) {
        std::string word;
        char c;
        while(file >> c) {
            if (std::isupper(c)) {
                word += c;
            } else {
                if (!word.empty()) {
                    content.PushBack(word);
                    word.clear();
                }
            }
        }
        file.close();
    } else {
        // to handle file not found
        std::cout << "File '" << file_path << "' not found." << std::endl;
    }
    return content;
}


// to handle function
// void TextFileHandler::WriteFile(const LinkedList<std::string> &content) {
//     std::ofstream file(file_path);
//     if (file.is_open()) {
//         file << content;
//         file.close();
//     } else {
//         std::cout << "Error writing to file '" << file_path << "'." << std::endl;
//     }
// }