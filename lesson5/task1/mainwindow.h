#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTimer>
#include <QTime>
#include <QTextBrowser>
#include <QPushButton>
#include <QMainWindow>

#include "stopwatch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void startBut();
    void updateTimer();
    void setBrowser();
    void clearTimerAndLap();



private:
    Ui::MainWindow *ui;
    Stopwatch *stopwatch;
    QString timerText = "";
    int lapCount = 1;
    QString lapBrowserText = "";

};
#endif // MAINWINDOW_H
