#ifndef THIS_PROJECT_CONTROLLER_H
#define THIS_PROJECT_CONTROLLER_H

#include "mainwindow.h"
#include <QObject>

class MainWindowController : public QObject {
  Q_OBJECT

public:
  explicit MainWindowController(MainWindow *main_window,
                                QObject *parent = nullptr)
      : QObject(parent), main_window_(main_window) {
    connect(main_window_->open_, SIGNAL(clicked(bool)), this, SLOT(Operate()));
    connect(main_window_->save_, SIGNAL(clicked(bool)), this, SLOT(Save()));
  }

public slots:
  void Operate();
  void Save();

private:
  MainWindow *main_window_;
};

#endif // THIS_PROJECT_CONTROLLER_H
