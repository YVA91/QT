#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QComboBox>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radBut_1->setText("Иран");
    ui->radBut_2->setText("Израиль");
    ui->radBut_1->setChecked(true);
    ui->comBox_iran->addItems({"Тегеран", "Мешхед", "Исфахан", "Кередж", "Шираз"});
    ui->comBox_izrail->addItems({"Иерусалим", "Тель-Авив", "Хайфа", "Ашдод", "Ришон-ле-Цион"});
    ui->comBox_iran->setDisabled(true);
    ui->radBut_1->connect(ui->radBut_1, &QRadioButton::toggled,ui->comBox_iran, &QComboBox::setDisabled);
    ui->radBut_2->connect(ui->radBut_2, &QRadioButton::toggled, [this](bool checked) {
    ui->comBox_izrail->setEnabled(!checked);
    });
    ui->pBut_fire->setText("Огонь!");
    ui->pBut_fire->setCheckable(true);

    QList<QProgressBar*> pBars = {
        ui->pBar_tegeran,
        ui->pBar_meshhed,
        ui->pBar_icfahan,
        ui->pBar_keradj,
        ui->pBar_shiraz,
        ui->pBar_ierusalim,
        ui->pBar_telaviv,
        ui->pBar_haifa,
        ui->pBar_ashdod,
        ui->pBar_Rishon
    };

    for (QProgressBar* progressBar : pBars) {
        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setFormat("%p%");
    }

    ui->pBut_fire->connect(ui->pBut_fire, &QPushButton::clicked, [this]() {
        QProgressBar *progressBar = nullptr;

        if (ui->comBox_iran->isEnabled()) {
            QString City = ui->comBox_iran->currentText();
            if (City == "Тегеран") {
                progressBar = ui->pBar_tegeran;
            } else if (City == "Мешхед") {
                progressBar = ui->pBar_meshhed;
            } else if (City == "Исфахан") {
                progressBar = ui->pBar_icfahan;
            } else if (City == "Кередж") {
                progressBar = ui->pBar_keradj;
            } else if (City == "Шираз") {
                progressBar = ui->pBar_shiraz;
            }
        }
        else if (ui->comBox_izrail->isEnabled()) {
            QString City = ui->comBox_izrail->currentText();
            if (City == "Иерусалим") {
                progressBar = ui->pBar_ierusalim;
            } else if (City == "Тель-Авив") {
                progressBar = ui->pBar_telaviv;
            } else if (City == "Хайфа") {
                progressBar = ui->pBar_haifa;
            } else if (City == "Ашдод") {
                progressBar = ui->pBar_ashdod;
            } else if (City == "Ришон-ле-Цион") {
                progressBar = ui->pBar_Rishon;
            }
        }

        if (progressBar) {
            int newValue = progressBar->value() + 10;
            if (newValue > 100) newValue = 0;
            progressBar->setValue(newValue);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}




