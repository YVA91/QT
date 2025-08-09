/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comBox_iran;
    QComboBox *comBox_izrail;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QProgressBar *pBar_ashdod;
    QLabel *label_3;
    QProgressBar *pBar_icfahan;
    QProgressBar *pBar_ierusalim;
    QProgressBar *pBar_keradj;
    QProgressBar *pBar_telaviv;
    QLabel *label_8;
    QProgressBar *pBar_tegeran;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_9;
    QProgressBar *pBar_meshhed;
    QLabel *label_4;
    QProgressBar *pBar_haifa;
    QLabel *label_7;
    QProgressBar *pBar_Rishon;
    QProgressBar *pBar_shiraz;
    QLabel *label_5;
    QLabel *label_10;
    QPushButton *pBut_fire;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QRadioButton *radBut_1;
    QRadioButton *radBut_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(311, 336);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName("gridLayout_4");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        comBox_iran = new QComboBox(groupBox_2);
        comBox_iran->setObjectName("comBox_iran");

        gridLayout_2->addWidget(comBox_iran, 0, 0, 1, 1);

        comBox_izrail = new QComboBox(groupBox_2);
        comBox_izrail->setObjectName("comBox_izrail");

        gridLayout_2->addWidget(comBox_izrail, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName("gridLayout");
        pBar_ashdod = new QProgressBar(groupBox_3);
        pBar_ashdod->setObjectName("pBar_ashdod");
        pBar_ashdod->setValue(24);

        gridLayout->addWidget(pBar_ashdod, 3, 3, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        pBar_icfahan = new QProgressBar(groupBox_3);
        pBar_icfahan->setObjectName("pBar_icfahan");
        pBar_icfahan->setValue(24);

        gridLayout->addWidget(pBar_icfahan, 2, 1, 1, 1);

        pBar_ierusalim = new QProgressBar(groupBox_3);
        pBar_ierusalim->setObjectName("pBar_ierusalim");
        pBar_ierusalim->setValue(24);

        gridLayout->addWidget(pBar_ierusalim, 0, 3, 1, 1);

        pBar_keradj = new QProgressBar(groupBox_3);
        pBar_keradj->setObjectName("pBar_keradj");
        pBar_keradj->setValue(24);

        gridLayout->addWidget(pBar_keradj, 3, 1, 1, 1);

        pBar_telaviv = new QProgressBar(groupBox_3);
        pBar_telaviv->setObjectName("pBar_telaviv");
        pBar_telaviv->setValue(24);

        gridLayout->addWidget(pBar_telaviv, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        pBar_tegeran = new QProgressBar(groupBox_3);
        pBar_tegeran->setObjectName("pBar_tegeran");
        pBar_tegeran->setValue(24);

        gridLayout->addWidget(pBar_tegeran, 0, 1, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        pBar_meshhed = new QProgressBar(groupBox_3);
        pBar_meshhed->setObjectName("pBar_meshhed");
        pBar_meshhed->setValue(24);

        gridLayout->addWidget(pBar_meshhed, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        pBar_haifa = new QProgressBar(groupBox_3);
        pBar_haifa->setObjectName("pBar_haifa");
        pBar_haifa->setValue(24);

        gridLayout->addWidget(pBar_haifa, 2, 3, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        pBar_Rishon = new QProgressBar(groupBox_3);
        pBar_Rishon->setObjectName("pBar_Rishon");
        pBar_Rishon->setValue(24);

        gridLayout->addWidget(pBar_Rishon, 4, 3, 1, 1);

        pBar_shiraz = new QProgressBar(groupBox_3);
        pBar_shiraz->setObjectName("pBar_shiraz");
        pBar_shiraz->setValue(24);

        gridLayout->addWidget(pBar_shiraz, 4, 1, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");

        gridLayout->addWidget(label_10, 4, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 2, 0, 1, 1);

        pBut_fire = new QPushButton(centralwidget);
        pBut_fire->setObjectName("pBut_fire");
        pBut_fire->setAutoRepeatDelay(300);

        gridLayout_4->addWidget(pBut_fire, 3, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        radBut_1 = new QRadioButton(groupBox);
        radBut_1->setObjectName("radBut_1");

        gridLayout_3->addWidget(radBut_1, 0, 0, 1, 1);

        radBut_2 = new QRadioButton(groupBox);
        radBut_2->setObjectName("radBut_2");

        gridLayout_3->addWidget(radBut_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 311, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\263\320\276\321\200\320\276\320\264\320\260 \320\264\320\273\321\217 \320\260\321\202\320\260\320\272\320\270:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\245\320\276\320\264 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\204\320\260\321\205\320\260\320\275", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\245\320\260\320\271\321\204\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\230\320\265\321\200\321\203\321\201\320\260\320\273\320\270\320\274", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\210\321\205\320\265\320\264", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\263\320\265\321\200\320\260\320\275", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\220\321\210\320\264\320\276\320\264", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\232\320\265\321\200\320\265\320\264\320\266", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\321\214-\320\220\320\262\320\270\320\262", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\260\320\267", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\210\320\276\320\275-\320\273\320\265-\320\246\320\270\320\276\320\275", nullptr));
        pBut_fire->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\201\321\202\320\276\321\200\320\276\320\275\321\203:", nullptr));
        radBut_1->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
        radBut_2->setText(QCoreApplication::translate("MainWindow", "RadioButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
