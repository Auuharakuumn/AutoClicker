#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_startSequenceEdit_keySequenceChanged(const QKeySequence &keySequence);

    void on_intervalBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QKeySequence defaultHotkey;
    QKeySequence hotkey;
    int clickDelay;
};

#endif // MAINWINDOW_H
