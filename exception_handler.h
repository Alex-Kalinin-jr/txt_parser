#ifndef EXCEPTION_HANDLER_H
#define EXCEPTION_HANDLER_H

#include <fstream>
#include <iostream>
#include <stdexcept>

class ExceptionHandler {
public:
  static ExceptionHandler &getInstance();

  void HandleException(const std::exception &e);

private:
  ExceptionHandler();

  ~ExceptionHandler();

  void WriteToFile(const std::string &text);

  std::ofstream log_file_;
};

#endif // EXCEPTION_HANDLER_H
