#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QTextBrowser>
#include <QPushButton>
#include <QMainWindow>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lapBut->setEnabled(false);
    stopwatch = new Stopwatch(this);
    connect(stopwatch->timer, &QTimer::timeout, this, &::MainWindow::updateTimer, Qt::AutoConnection);
    connect( ui->lapBut, &QPushButton::clicked, this, &MainWindow::setBrowser, Qt::AutoConnection);
    connect(ui->startBut, &QPushButton::clicked, this, &MainWindow::startBut, Qt::AutoConnection);
    connect(ui->clearBut, &QPushButton::clicked, this, &MainWindow::clearTimerAndLap, Qt::AutoConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startBut()
{
    if (!stopwatch->isTimer) {
        ui->lapBut->setEnabled(true);
        ui->startBut->setText("Стоп");
    } else {
        ui->lapBut->setEnabled(false);
        ui->startBut->setText("Старт");
    }
    stopwatch->on_start_stop();
}

void MainWindow::updateTimer()
{
    int time;
    time = stopwatch->setTextTimer();
    timerText = QTime(0, 0, 0).addMSecs(time).toString("hh:mm:ss.zzz");
    ui->timer->setText(timerText);
}

void MainWindow::setBrowser()
{
    int elapsedMs = 0;
    elapsedMs = stopwatch->setBrowserText(lapCount);
    lapBrowserText  = QString("Круг %1, время: %2 сек").arg(lapCount).arg(elapsedMs / 1000.0, 0, 'f', 2);
    ui->lap->append(lapBrowserText);
    lapCount++;

}

void MainWindow::clearTimerAndLap()
{
    stopwatch->clear();
    ui->lap->clear();
    stopwatch->on_start_stop();
    lapCount = 1;
}

