#include "mainwindow.h"

#include <QApplication>

#include "controller.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  MainWindowController controller(&w, nullptr);
  w.show();
  return a.exec();
}
