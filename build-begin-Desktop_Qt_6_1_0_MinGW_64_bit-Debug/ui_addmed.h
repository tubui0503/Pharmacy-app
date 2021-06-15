/********************************************************************************
** Form generated from reading UI file 'addmed.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMED_H
#define UI_ADDMED_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Addmed
{
public:
    QLabel *label_5;
    QLabel *kho_thuoc;
    QLineEdit *so_luong;
    QLabel *label_3;
    QLineEdit *ten_thuoc;
    QLabel *label_7;
    QLabel *label;
    QLineEdit *ma_thuoc;
    QLineEdit *don_vi;
    QLineEdit *don_gia;
    QLabel *label_6;
    QPushButton *pushButton;

    void setupUi(QDialog *Addmed)
    {
        if (Addmed->objectName().isEmpty())
            Addmed->setObjectName(QString::fromUtf8("Addmed"));
        Addmed->resize(409, 504);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Addmed->setWindowIcon(icon);
        label_5 = new QLabel(Addmed);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 230, 51, 31));
        kho_thuoc = new QLabel(Addmed);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(10, 20, 371, 81));
        so_luong = new QLineEdit(Addmed);
        so_luong->setObjectName(QString::fromUtf8("so_luong"));
        so_luong->setGeometry(QRect(150, 330, 221, 31));
        label_3 = new QLabel(Addmed);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 180, 121, 31));
        ten_thuoc = new QLineEdit(Addmed);
        ten_thuoc->setObjectName(QString::fromUtf8("ten_thuoc"));
        ten_thuoc->setGeometry(QRect(150, 180, 221, 31));
        label_7 = new QLabel(Addmed);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 330, 71, 31));
        label = new QLabel(Addmed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 130, 111, 31));
        ma_thuoc = new QLineEdit(Addmed);
        ma_thuoc->setObjectName(QString::fromUtf8("ma_thuoc"));
        ma_thuoc->setGeometry(QRect(150, 130, 221, 31));
        don_vi = new QLineEdit(Addmed);
        don_vi->setObjectName(QString::fromUtf8("don_vi"));
        don_vi->setGeometry(QRect(150, 230, 221, 31));
        don_gia = new QLineEdit(Addmed);
        don_gia->setObjectName(QString::fromUtf8("don_gia"));
        don_gia->setGeometry(QRect(150, 280, 221, 31));
        label_6 = new QLabel(Addmed);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 280, 51, 31));
        pushButton = new QPushButton(Addmed);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 410, 171, 41));

        retranslateUi(Addmed);

        QMetaObject::connectSlotsByName(Addmed);
    } // setupUi

    void retranslateUi(QDialog *Addmed)
    {
        Addmed->setWindowTitle(QCoreApplication::translate("Addmed", "ADDMED", nullptr));
        label_5->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">UNIT</span></p></body></html>", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:600; color:#0000ff;\">ADD MEDICINE</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">MED NAME</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">AMOUNT</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">MED CODE</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Addmed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">PRICE</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("Addmed", "ADD MED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Addmed: public Ui_Addmed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMED_H
