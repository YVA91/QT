#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345
#define BIND_PORT_SEND 12346

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket(  );
    void ReadDatagram( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );


private slots:
    void readPendingDatagrams();

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* serviceUdpSocketSend;



signals:
    void sig_sendTimeToGUI(QHostAddress senderAddress, qint64 size);

};

#endif // UDPWORKER_H
