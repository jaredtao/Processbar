#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    resize(1024, 768);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(0,0,0));
    setAutoFillBackground(true);
    setPalette(palette);
    mBar = new ProgressBar(this);
    mBar->show();
    startTimer(1000 / 60);
}

void MainWindow::timerEvent(QTimerEvent *) {
    int value = (int)(mBar->current() + 3) % 360;
    mBar->setCurrent(value);
    mBar->update();
}
