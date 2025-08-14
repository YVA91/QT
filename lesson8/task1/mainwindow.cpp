#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lb_statusConnect->setStyleSheet("color:red");
    ui->pb_request->setEnabled(false);

    dataDb = new DbData(this);
    dataBase = new DataBase(this);
    msg = new QMessageBox(this);

    dataForConnect.resize(NUM_DATA_FOR_CONNECT_TO_DB);

    dataBase->AddDataBase(POSTGRE_DRIVER, DB_NAME);

    connect(dataDb, &DbData::sig_sendData, this, [&](QVector<QString> receivData){
        dataForConnect = receivData;
    });


    connect(dataBase, &DataBase::sig_SendTableModel, this, static_cast<void (MainWindow::*)(QSqlTableModel*)>(&MainWindow::ScreenDataFromDB));
    connect(dataBase, &DataBase::sig_SendQueryModel, this, static_cast<void (MainWindow::*)(QSqlQueryModel*)>(&MainWindow::ScreenDataFromDB));

    connect(dataBase, &DataBase::sig_SendStatusConnection, this, &MainWindow::ReceiveStatusConnectionToDB);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_act_addData_triggered()
{
    dataDb->show();
}

void MainWindow::on_act_connect_triggered()
{

    if(ui->lb_statusConnect->text() == "Отключено"){

       ui->lb_statusConnect->setText("Подключение");
       ui->lb_statusConnect->setStyleSheet("color : black");

       auto conn = [&]{dataBase->ConnectToDataBase(dataForConnect);};
       QtConcurrent::run(conn);

    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        ui->lb_statusConnect->setText("Отключено");
        ui->act_connect->setText("Подключиться");
        ui->lb_statusConnect->setStyleSheet("color:red");
        ui->pb_request->setEnabled(false);
    }

}

void MainWindow::on_pb_request_clicked()
{
        on_pb_clear_clicked();
        int type = ui->cb_category->currentIndex();
        QString request;

        switch (type)
        {
        case requestType::requestAllFilms:
            request = "SELECT title, description FROM film";

            break;
        case requestType::requestComedy:
            request = QString("SELECT title, description FROM film f "
                      "JOIN film_category fc ON f.film_id = fc.film_id "
                      "JOIN category c ON c.category_id = fc.category_id "
                      "WHERE c.name = 'Comedy'");
            break;
        case requestType::requestHorrors:
            request = QString("SELECT title, description FROM film f "
                      "JOIN film_category fc ON f.film_id = fc.film_id "
                      "JOIN category c ON c.category_id = fc.category_id "
                      "WHERE c.name = 'Horror'");
            break;
        }

        dataBase->RequestToDB(request);
}

void MainWindow::ScreenDataFromDB(QSqlTableModel* model)
{

    ui->tb_result->setModel(model);
        ui->tb_result->hideColumn(0);
        for (int i = 3; i < model->columnCount(); ++i)
            ui->tb_result->hideColumn(i);
        ui->tb_result->resizeColumnsToContents();
        ui->tb_result->show();
}

void MainWindow::ScreenDataFromDB(QSqlQueryModel* model)
{
    ui->tb_result->setModel(model);
    ui->tb_result->resizeColumnsToContents();
    ui->tb_result->show();
}

void MainWindow::ReceiveStatusConnectionToDB(bool status)
{
    if(status){
        ui->act_connect->setText("Отключиться");
        ui->lb_statusConnect->setText("Подключено к БД");
        ui->lb_statusConnect->setStyleSheet("color:green");
        ui->pb_request->setEnabled(true);
    }
    else{
        dataBase->DisconnectFromDataBase(DB_NAME);
        msg->setIcon(QMessageBox::Critical);
        msg->setText(dataBase->GetLastError().text());
        ui->lb_statusConnect->setText("Отключено");
        ui->lb_statusConnect->setStyleSheet("color:red");
        msg->exec();
    }

}


void MainWindow::on_pb_clear_clicked()
{
    if (ui->tb_result->model())
    {
        ui->tb_result->setModel(nullptr);
    }
}


