#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QString>

QString MainWindow::OpenFile() {
  QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                                  tr("Text Files (*.txt)"));
  return filename;
}

QString MainWindow::SaveFile() {
  QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), ".",
                                                  tr("Text Files (*.txt"));
  return filename;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setCentralWidget(new QWidget(this));
  QGridLayout *layout = new QGridLayout(this);
  centralWidget()->setLayout(layout);

  open_ = new QPushButton(tr("Open"), this);
  save_ = new QPushButton(tr("Save"), this);
  parse_bttn_ = new QPushButton(tr("Parse"), this);

  layout->addWidget(open_, 0, 0, 1, 1);
  layout->addWidget(save_, 0, 1, 1, 1);
  layout->addWidget(parse_bttn_, 0, 2, 1, 1);
}

MainWindow::~MainWindow() { delete ui; }
