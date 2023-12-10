#include "controller.h"

void MainWindowController::Operate() {
  QString filename = main_window_->OpenFile();
}

void MainWindowController::Save() {
  QString filename = main_window_->SaveFile();
}
