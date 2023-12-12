#include "mainwindow.h"

#include <QApplication>

#include "controller.h"

int main(int argc, char *argv[]) {
  try {
    QApplication a(argc, argv);
    MainWindow window;
    UpperCaseFacade facade;
    MainWindowController controller(&window, &facade, nullptr);
    window.show();
  } catch (const std::exception &e) {
    ExceptionHandler::getInstance().HandleException(e);
  }

  return a.exec();
}
