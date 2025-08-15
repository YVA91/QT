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

    connect( ui->lapBut, &QPushButton::clicked, this, &MainWindow::setBrowser, Qt::AutoConnection);
    connect(ui->startBut, &QPushButton::clicked, this, &MainWindow::startBut, Qt::AutoConnection);
    connect(ui->clearBut, &QPushButton::clicked, this, &MainWindow::clearTimerAndLap, Qt::AutoConnection);

    connect(&stopwatch, &Stopwatch::SetStopWath, this, &MainWindow::updateTimer, Qt::AutoConnection);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startBut()
{
    if (!isTimer) {
        ui->lapBut->setEnabled(true);
        ui->startBut->setText("Стоп");
        stopwatch.on_start();
        isTimer = true;

    } else {
        ui->lapBut->setEnabled(false);
        ui->startBut->setText("Старт");
        stopwatch.on_stop();
        isTimer = false;
    }

}

void MainWindow::updateTimer(const QString& time)
{

    ui->timer->setText(time);
}

void MainWindow::setBrowser()
{
    elapsedMs = stopwatch.setBrowserText();
    lapBrowserText  = QString("Круг %1, время: %2 сек").arg(lapCount).arg(elapsedMs / 1000.0);
    ui->lap->append(lapBrowserText);
    lapCount++;

}

void MainWindow::clearTimerAndLap()
{
    stopwatch.clear();
    ui->lap->clear();
    ui->startBut->setText("Старт");
    lapCount = 1;
    isTimer = false;
}

