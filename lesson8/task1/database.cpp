#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{

    dataBase = new QSqlDatabase();
    queryModel = new QSqlQueryModel();
    tableModel = nullptr;

}

DataBase::~DataBase()
{
    delete dataBase;
    delete queryModel;
}

void DataBase::AddDataBase(QString driver, QString nameDB)
{

    *dataBase = QSqlDatabase::addDatabase(driver, nameDB);

}

void DataBase::ConnectToDataBase(QVector<QString> data)
{

    dataBase->setHostName(data[hostName]);
    dataBase->setDatabaseName(data[dbName]);
    dataBase->setUserName(data[login]);
    dataBase->setPassword(data[pass]);
    dataBase->setPort(data[port].toInt());

    if (tableModel) {
        delete tableModel;
        }

    tableModel = new QSqlTableModel(nullptr, *dataBase);

    bool status = dataBase->open();
    emit sig_SendStatusConnection(status);

}

void DataBase::DisconnectFromDataBase(QString nameDb)
{

    *dataBase = QSqlDatabase::database(nameDb);
    dataBase->close();

}

void DataBase::RequestToDB(QString request)
{
    queryModel->setQuery(request, *dataBase);
        queryModel->setHeaderData(0, Qt::Horizontal, tr("Название фильма"));
        queryModel->setHeaderData(1, Qt::Horizontal, tr("Описание фильма"));

        emit sig_SendQueryModel(queryModel);

}

void DataBase::GetTableModel()
{
    tableModel->setTable("film");
    tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    tableModel->select();
    tableModel->setHeaderData(1, Qt::Horizontal, tr("Название фильма"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("Описание фильма"));

    emit sig_SendTableModel(tableModel);
}

QSqlError DataBase::GetLastError()
{
    return dataBase->lastError();
}
