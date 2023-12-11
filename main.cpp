#include "mainwindow.h"

#include <QApplication>

#include "controller.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow window;
  UpperCaseFacade facade;
  MainWindowController controller(&window, &facade, nullptr);
  window.show();
  return a.exec();
}
