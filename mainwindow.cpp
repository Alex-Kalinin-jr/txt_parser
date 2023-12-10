#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QPushButton>
#include <QString>

QString &MainWindow::OpenFile() {
  QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                                  tr("Text Files (*.txt)"));
  return filename;
}

QString &MainWindow::SaveFile() {
  QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), ".",
                                                  tr("Text Files (*.txt"));
  return filename;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  open_ = new QPushButton(tr("Open"), this);
  save_ = new QPushButton(tr("Save"), this);
}

MainWindow::~MainWindow() { delete ui; }
