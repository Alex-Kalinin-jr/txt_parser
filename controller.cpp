#include <iostream>

#include "controller.h"
#include "model/facade.h"

void MainWindowController::Open() {
  QString filename = main_window_->OpenFile();
  facade_->ReadFile(filename.toStdString());
}

void MainWindowController::Operate() {
  facade_->Handlefile();
  std::cout << "file handled" << std::endl;
}

void MainWindowController::Save() {
  QString filename = main_window_->SaveFile();
  std::cout << filename.toStdString() << std::endl;
}
