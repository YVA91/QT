#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpWorker = new UDPworker(this);
    udpWorker->InitSocket();

    connect(udpWorker, &UDPworker::sig_sendTimeToGUI, this, &MainWindow::DisplayTime);
    connect(udpWorker, &UDPworker::sig_sendData, this, &MainWindow::MyDisplayTime);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [&]{

        QDateTime dateTime = QDateTime::currentDateTime();

        QByteArray dataToSend;
        QDataStream outStr(&dataToSend, QIODevice::WriteOnly);

        outStr << dateTime;

        udpWorker->SendDatagram(dataToSend);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_start_clicked()
{
    timer->start(TIMER_DELAY);
}


void MainWindow::DisplayTime(QDateTime data)
{
    counterPck++;
    if(counterPck % 20 == 0){
        ui->te_result->clear();
    }

    ui->te_result->append("Текущее время: " + data.toString() + ". "
                "Принято пакетов " + QString::number(counterPck));


}

void MainWindow::on_pb_stop_clicked()
{
    timer->stop();
}

void MainWindow::MyDisplayTime(QHostAddress senderAddress, qint64 size)
{

    QString displayText = QString("Принято сообщение от %1, размер сообщения (байт): %2\n")
                                 .arg(senderAddress.toString())
                                 .arg(size);

    ui->te_result->append(displayText);

}

void MainWindow::on_pb_send_clicked()
{
    QByteArray data = ui->te_send->toPlainText().toUtf8();
    udpWorker->SendMyDatagram(data);
    ui->te_send->clear();

}

