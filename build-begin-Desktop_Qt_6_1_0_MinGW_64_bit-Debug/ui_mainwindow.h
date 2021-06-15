/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *hoten;
    QLineEdit *sdt;
    QPushButton *btn_donthuoc;
    QPushButton *themmoi;
    QTableView *tableView;
    QSpinBox *CountThuoc;
    QComboBox *comboBox;
    QPushButton *search;
    QPushButton *update;
    QLCDNumber *sum;
    QLabel *label_6;
    QPushButton *med;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *kho_thuoc;
    QLabel *kho_thuoc_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(421, 573);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hoten = new QLineEdit(centralwidget);
        hoten->setObjectName(QString::fromUtf8("hoten"));
        hoten->setGeometry(QRect(81, 61, 142, 26));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        hoten->setFont(font);
        sdt = new QLineEdit(centralwidget);
        sdt->setObjectName(QString::fromUtf8("sdt"));
        sdt->setGeometry(QRect(81, 95, 142, 26));
        sdt->setFont(font);
        btn_donthuoc = new QPushButton(centralwidget);
        btn_donthuoc->setObjectName(QString::fromUtf8("btn_donthuoc"));
        btn_donthuoc->setGeometry(QRect(292, 99, 113, 28));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        btn_donthuoc->setFont(font1);
        themmoi = new QPushButton(centralwidget);
        themmoi->setObjectName(QString::fromUtf8("themmoi"));
        themmoi->setGeometry(QRect(292, 135, 111, 28));
        themmoi->setFont(font1);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 250, 371, 221));
        CountThuoc = new QSpinBox(centralwidget);
        CountThuoc->setObjectName(QString::fromUtf8("CountThuoc"));
        CountThuoc->setGeometry(QRect(345, 62, 53, 29));
        QFont font2;
        font2.setBold(false);
        CountThuoc->setFont(font2);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(81, 129, 65, 26));
        comboBox->setFont(font);
        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(292, 171, 111, 28));
        search->setFont(font1);
        update = new QPushButton(centralwidget);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(320, 470, 80, 25));
        update->setFont(font1);
        sum = new QLCDNumber(centralwidget);
        sum->setObjectName(QString::fromUtf8("sum"));
        sum->setGeometry(QRect(70, 180, 151, 41));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        sum->setFont(font3);
        sum->setFrameShape(QFrame::Box);
        sum->setFrameShadow(QFrame::Plain);
        sum->setLineWidth(3);
        sum->setMidLineWidth(0);
        sum->setDigitCount(15);
        sum->setSegmentStyle(QLCDNumber::Flat);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 190, 55, 16));
        label_6->setFont(font3);
        med = new QPushButton(centralwidget);
        med->setObjectName(QString::fromUtf8("med"));
        med->setGeometry(QRect(291, 208, 111, 28));
        med->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 61, 49, 23));
        label_7->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 62, 65, 23));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 95, 52, 23));
        label_10->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 129, 62, 23));
        label_11->setFont(font);
        kho_thuoc = new QLabel(centralwidget);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(0, 10, 411, 41));
        QFont font4;
        font4.setPointSize(7);
        kho_thuoc->setFont(font4);
        kho_thuoc_2 = new QLabel(centralwidget);
        kho_thuoc_2->setObjectName(QString::fromUtf8("kho_thuoc_2"));
        kho_thuoc_2->setGeometry(QRect(0, 180, 71, 41));
        kho_thuoc_2->setFont(font4);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NhaThuoc", nullptr));
        btn_donthuoc->setText(QCoreApplication::translate("MainWindow", "ADD MED", nullptr));
        themmoi->setText(QCoreApplication::translate("MainWindow", "CREATE", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Male", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Female", nullptr));

        search->setText(QCoreApplication::translate("MainWindow", "SEARCH", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "VND", nullptr));
        med->setText(QCoreApplication::translate("MainWindow", "STORE", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Amount", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Phone", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#0000ff;\">CUSTOMER INFORMATION</span></p></body></html>", nullptr));
        kho_thuoc_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#0000ff;\">TOTAL</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
