#ifndef DATABASE_H
#define DATABASE_H

#include <QTableWidget>
#include <QObject>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQueryModel>

#define POSTGRE_DRIVER "QPSQL"
#define DB_NAME "MyDB"
#define NUM_DATA_FOR_CONNECT_TO_DB 5

enum fieldsForConnect{
    hostName = 0,
    dbName = 1,
    login = 2,
    pass = 3,
    port = 4
};

enum requestType{

    requestAllFilms = 0,
    requestComedy   = 1,
    requestHorrors  = 2

};



class DataBase : public QObject
{
    Q_OBJECT

public:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

    void AddDataBase(QString driver, QString nameDB = "");
    void DisconnectFromDataBase(QString nameDb = "");
    void RequestToDB(QString request);
    QSqlError GetLastError(void);
    void ConnectToDataBase(QVector<QString> dataForConnect);
    void GetTableModel();

signals:

   void sig_SendStatusConnection(bool);
   void sig_SendTableModel(QSqlTableModel* model);
   void sig_SendQueryModel(QSqlQueryModel* model);

private:

    QSqlDatabase* dataBase;
    QSqlQueryModel* queryModel;
    QSqlTableModel* tableModel;

};

#endif // DATABASE_H
