#include "exception_handler.h"

ExceptionHandler &ExceptionHandler::getInstance() {
  static ExceptionHandler instance;
  return instance;
}

void ExceptionHandler::HandleException(const std::exception &e) {
  std::string exceptionText = e.what();
  WriteToFile(exceptionText);
  std::cerr << "Exception occurred: " << exceptionText << std::endl;
}

ExceptionHandler::ExceptionHandler() {
  log_file_.open("exception_log.txt", std::ios::app);
  if (!log_file_.is_open()) {
    std::cerr << "Failed to open log file!" << std::endl;
  }
}

ExceptionHandler::~ExceptionHandler() {
  if (log_file_.is_open()) {
    log_file_.close();
  }
}

void ExceptionHandler::WriteToFile(const std::string &text) {
  if (log_file_.is_open()) {
    log_file_ << text << std::endl;
  }
}
