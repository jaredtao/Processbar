#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(0,0,0));
    setAutoFillBackground(true);
    setPalette(palette);
    bar = new ProgressBar(this);
    bar->show();
    startTimer(1000 / 60);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete bar;
}
void MainWindow::timerEvent(QTimerEvent *)
{
    int value = (int)(bar->current() + 3) % 360;
    bar->setCurrent(value);
    bar->update();
}
