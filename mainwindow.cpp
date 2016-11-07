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
    startTimer(100);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete bar;
}
void MainWindow::timerEvent(QTimerEvent *)
{
    bar->setCurrent(bar->current() + 5);
    bar->update();
}
