#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    defaultHotkey("f7")
{
    this->ui->setupUi(this);

    this->ui->intervalBox->setMinimum(1);
    this->ui->intervalBox->setMaximum(60 * 60 * 1000); // One hour in milliseconds

    this->ui->startSequenceEdit->setKeySequence(this->defaultHotkey);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked() {

}

void MainWindow::on_startSequenceEdit_keySequenceChanged(const QKeySequence &keySequence) {
    this->hotkey = keySequence;
}

void MainWindow::on_intervalBox_valueChanged(int arg1) {
    this->clickDelay = arg1;
}
