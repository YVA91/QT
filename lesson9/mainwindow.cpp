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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayTime(QHostAddress senderAddress, qint64 size)
{

    QString displayText = QString("Принято сообщение от %1, размер сообщения (байт): %2\n")
                                 .arg(senderAddress.toString())
                                 .arg(size);

    ui->te_result->append(displayText);

}


void MainWindow::on_pb_send_clicked()
{
    QByteArray data = ui->te_send->toPlainText().toUtf8();
    udpWorker->SendDatagram(data);
    ui->te_send->clear();
}


