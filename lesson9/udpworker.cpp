#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{
}

void UDPworker::InitSocket() {

    serviceUdpSocket = new QUdpSocket(this);
    if (!serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT)) {
        qDebug() << "Bind (receive) failed:" << serviceUdpSocket->errorString();
    }
    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

    serviceUdpSocketSend = new QUdpSocket(this);
    if (!serviceUdpSocketSend->bind(QHostAddress::LocalHost, BIND_PORT_SEND)) {
        qDebug() << "Bind (send) failed:" << serviceUdpSocketSend->errorString();
    }
}

void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();
    emit sig_sendTimeToGUI(datagram.senderAddress(), data.size());
 }


void UDPworker::SendDatagram(QByteArray data)
{
    serviceUdpSocketSend->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}

void UDPworker::readPendingDatagrams(  )
{

    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}
