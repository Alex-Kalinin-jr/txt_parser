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
  try {
    QString filename = main_window_->OpenFile();
    facade_->ReadFile(filename.toStdString());
    main_window_->Notify("File was opened and read");
  } catch (...) {
    main_window_->Notify("Some errors occur while open and read file");
  }
}

void MainWindowController::Operate() {
  try {
    facade_->Handlefile();
    main_window_->Notify("File was parsed and sorted");
  } catch (...) {
    main_window_->Notify("Some errors occur during data parsing");
  }
}

void MainWindowController::Save() {
  try {
    std::string filename = main_window_->SaveFile().toStdString();
    facade_->WriteFile(filename);
    main_window_->Notify("File was saved");
  } catch (...) {
    main_window_->Notify("Some errors occured during data saving");
  }
}
