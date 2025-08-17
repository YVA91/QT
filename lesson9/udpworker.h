#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345
#define BIND_PORT_DATA_SEND 12347


class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );
    void SendMyDatagram(QByteArray data );

    void MyReadDatagram( QNetworkDatagram datagram);


private slots:
    void readPendingDatagrams(void);
    void MyreadPendingDatagrams(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* serviceUdpDataSend;


signals:
    void sig_sendTimeToGUI(QDateTime data);

    void sig_sendData(QHostAddress senderAddress, qint64 size);

};

#endif // UDPWORKER_H
