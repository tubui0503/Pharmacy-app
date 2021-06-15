/********************************************************************************
** Form generated from reading UI file 'updatemed.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEMED_H
#define UI_UPDATEMED_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Updatemed
{
public:
    QLineEdit *ma_thuoc;
    QLineEdit *don_gia;
    QLabel *label_7;
    QLineEdit *ten_thuoc;
    QLabel *label;
    QLabel *kho_thuoc;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *don_vi;
    QLineEdit *so_luong;
    QLabel *label_3;
    QPushButton *update_bt;

    void setupUi(QDialog *Updatemed)
    {
        if (Updatemed->objectName().isEmpty())
            Updatemed->setObjectName(QString::fromUtf8("Updatemed"));
        Updatemed->resize(540, 424);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Updatemed->setWindowIcon(icon);
        ma_thuoc = new QLineEdit(Updatemed);
        ma_thuoc->setObjectName(QString::fromUtf8("ma_thuoc"));
        ma_thuoc->setGeometry(QRect(200, 100, 261, 31));
        QFont font;
        font.setPointSize(12);
        ma_thuoc->setFont(font);
        don_gia = new QLineEdit(Updatemed);
        don_gia->setObjectName(QString::fromUtf8("don_gia"));
        don_gia->setGeometry(QRect(200, 250, 261, 31));
        don_gia->setFont(font);
        label_7 = new QLabel(Updatemed);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 300, 81, 31));
        label_7->setFont(font);
        ten_thuoc = new QLineEdit(Updatemed);
        ten_thuoc->setObjectName(QString::fromUtf8("ten_thuoc"));
        ten_thuoc->setGeometry(QRect(200, 150, 261, 31));
        ten_thuoc->setFont(font);
        label = new QLabel(Updatemed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 100, 91, 31));
        label->setFont(font);
        kho_thuoc = new QLabel(Updatemed);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(41, 0, 461, 81));
        label_5 = new QLabel(Updatemed);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 200, 51, 31));
        label_5->setFont(font);
        label_6 = new QLabel(Updatemed);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 250, 61, 31));
        label_6->setFont(font);
        don_vi = new QLineEdit(Updatemed);
        don_vi->setObjectName(QString::fromUtf8("don_vi"));
        don_vi->setGeometry(QRect(200, 200, 261, 31));
        don_vi->setFont(font);
        so_luong = new QLineEdit(Updatemed);
        so_luong->setObjectName(QString::fromUtf8("so_luong"));
        so_luong->setGeometry(QRect(200, 300, 261, 31));
        so_luong->setFont(font);
        label_3 = new QLabel(Updatemed);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 150, 81, 31));
        label_3->setFont(font);
        update_bt = new QPushButton(Updatemed);
        update_bt->setObjectName(QString::fromUtf8("update_bt"));
        update_bt->setGeometry(QRect(180, 350, 121, 31));

        retranslateUi(Updatemed);

        QMetaObject::connectSlotsByName(Updatemed);
    } // setupUi

    void retranslateUi(QDialog *Updatemed)
    {
        Updatemed->setWindowTitle(QCoreApplication::translate("Updatemed", "UPDATEMED", nullptr));
        label_7->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">AMOUNT</span></p><p><span style=\" font-weight:600;\"><br/></span></p><p><span style=\" font-weight:600;\"><br/></span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">MED CODE</span></p></body></html>", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:600; color:#0000ff;\">UPDATE MEDICINE</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">UNIT</span></p><p><span style=\" font-weight:600;\"><br/></span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">PRICE</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Updatemed", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">NAME</span></p></body></html>", nullptr));
        update_bt->setText(QCoreApplication::translate("Updatemed", "UPDATE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Updatemed: public Ui_Updatemed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEMED_H
