#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

    serviceUdpDataSend = new QUdpSocket(this);
    serviceUdpDataSend ->bind(QHostAddress::LocalHost, BIND_PORT_DATA_SEND);
    connect(serviceUdpDataSend, &QUdpSocket::readyRead, this, &UDPworker::MyreadPendingDatagrams);

}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;

    emit sig_sendTimeToGUI(dateTime);
}

void UDPworker::MyReadDatagram(QNetworkDatagram МуData)
{
    QByteArray data;
    data = МуData.data();
    emit sig_sendData(МуData.senderAddress(), data.size());

}
/*!
 * @brief Метод осуществляет опередачу датаграммы
 */


void UDPworker::SendDatagram(QByteArray data)
{
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);
}


void UDPworker::SendMyDatagram(QByteArray data)
{
    serviceUdpDataSend->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT_DATA_SEND);

}

/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{

    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}

void UDPworker::MyreadPendingDatagrams( void )
{

    while(serviceUdpDataSend->hasPendingDatagrams()){
            QNetworkDatagram МуData = serviceUdpDataSend->receiveDatagram();
            MyReadDatagram(МуData);
    }

}
