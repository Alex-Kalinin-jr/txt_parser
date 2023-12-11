#ifndef THIS_PROJECT_CONTROLLER_H
#define THIS_PROJECT_CONTROLLER_H

#include "mainwindow.h"
#include "model/facade.h"
#include <QObject>

class MainWindowController : public QObject {
  Q_OBJECT

public:
  explicit MainWindowController(MainWindow *main_window,
                                UpperCaseFacade *facade,
                                QObject *parent = nullptr)
      : QObject(parent), main_window_(main_window), facade_(facade) {
    connect(main_window_->open_, SIGNAL(clicked(bool)), this, SLOT(Open()));
    connect(main_window_->parse_bttn_, SIGNAL(clicked(bool)), this,
            SLOT(Operate()));
    connect(main_window_->save_, SIGNAL(clicked(bool)), this, SLOT(Save()));
  }

public slots:
  void Open();
  void Save();
  void Operate();

private:
  MainWindow *main_window_;
  UpperCaseFacade *facade_;
};

#endif // THIS_PROJECT_CONTROLLER_H
