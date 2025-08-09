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
    stopwatch->timer = new QTimer(this);
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
    } else {
        ui->lapBut->setEnabled(false);
    }

    stopwatch->on_start_stop();
    ui->startBut->setText(stopwatch->butStartStopText);
}

void MainWindow::updateTimer()
{
    stopwatch->setTextTimer();
    ui->timer->setText(stopwatch->timerText);
}

void MainWindow::setBrowser()
{
    stopwatch->setBrowserText();
    ui->lap->append(stopwatch->lapBrowserText);

}

void MainWindow::clearTimerAndLap()
{
    stopwatch->clear();
    ui->lap->clear();
    ui->timer->setText("");
}

