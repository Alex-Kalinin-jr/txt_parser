#ifndef THIS_PROJECT_FACADE_H
#define THIS_PROJECT_FACADE_H

#include "list.h"
#include "text_file_handler.h"

class UpperCaseFacade {
    public:
        UpperCaseFacade() {};
        bool HandleFile(const std::string& file_path);
};

#endif // THIS_PROJECT_FACADE_H