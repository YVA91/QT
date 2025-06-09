#include <QCoreApplication>
#include <QHostInfo>
#include <QDebug>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHostInfo info;
    QSqlDatabase data;

    QString localhost =  QHostInfo::localHostName();

    qDebug() << localhost;

    return a.exec();
}
