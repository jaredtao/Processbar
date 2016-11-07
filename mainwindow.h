#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "progressbar.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void timerEvent(QTimerEvent *) override;
private:
    Ui::MainWindow *ui;
    ProgressBar *bar;
};

#endif // MAINWINDOW_H
