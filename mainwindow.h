#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressbar.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
protected:
    void timerEvent(QTimerEvent *) override;
private:
    ProgressBar *mBar = nullptr;
};

#endif // MAINWINDOW_H
