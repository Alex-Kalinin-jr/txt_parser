#include <iostream>

#include "controller.h"
#include "model/facade.h"

void MainWindowController::Operate() {
  QString filename = main_window_->OpenFile();
  facade_->ReadFile(filename.toStdString());
}

void MainWindowController::Save() {
  QString filename = main_window_->SaveFile();
  std::cout << filename.toStdString() << std::endl;
}
