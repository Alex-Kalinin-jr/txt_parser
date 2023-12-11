#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  QPushButton *parse_bttn_;
  QPushButton *open_;
  QPushButton *save_;
  ~MainWindow();

  QString OpenFile();
  QString SaveFile();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
