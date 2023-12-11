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
                                QObject *parent = nullptr);

public slots:
  void Open();
  void Save();
  void Operate();

private:
  MainWindow *main_window_;
  UpperCaseFacade *facade_;
};

#endif // THIS_PROJECT_CONTROLLER_H
