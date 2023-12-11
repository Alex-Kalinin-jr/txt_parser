#include <iostream>

#include "controller.h"
#include "model/facade.h"

MainWindowController::MainWindowController(MainWindow *main_window,
                                           UpperCaseFacade *facade,
                                           QObject *parent)
    : QObject(parent), main_window_(main_window), facade_(facade) {
  connect(main_window_->open_, SIGNAL(clicked(bool)), this, SLOT(Open()));
  connect(main_window_->parse_bttn_, SIGNAL(clicked(bool)), this,
          SLOT(Operate()));
  connect(main_window_->save_, SIGNAL(clicked(bool)), this, SLOT(Save()));
}

void MainWindowController::Open() {
  QString filename = main_window_->OpenFile();
  facade_->ReadFile(filename.toStdString());
}

void MainWindowController::Operate() { facade_->Handlefile(); }

void MainWindowController::Save() {
  std::string filename = main_window_->SaveFile().toStdString();
  facade_->WriteFile(filename);
}
