/********************************************************************************
** Form generated from reading UI file 'timthuoc.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMTHUOC_H
#define UI_TIMTHUOC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Timthuoc
{
public:
    QTableWidget *table;
    QLabel *label_2;
    QPushButton *find;
    QLabel *kho_thuoc;
    QPushButton *update;
    QLineEdit *med_name;

    void setupUi(QDialog *Timthuoc)
    {
        if (Timthuoc->objectName().isEmpty())
            Timthuoc->setObjectName(QString::fromUtf8("Timthuoc"));
        Timthuoc->resize(615, 355);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Timthuoc->setWindowIcon(icon);
        table = new QTableWidget(Timthuoc);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(21, 108, 551, 192));
        table->setAlternatingRowColors(false);
        table->setShowGrid(true);
        table->setGridStyle(Qt::SolidLine);
        table->horizontalHeader()->setDefaultSectionSize(125);
        table->horizontalHeader()->setStretchLastSection(true);
        label_2 = new QLabel(Timthuoc);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 72, 201, 23));
        find = new QPushButton(Timthuoc);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(493, 72, 80, 28));
        kho_thuoc = new QLabel(Timthuoc);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(60, 0, 464, 63));
        update = new QPushButton(Timthuoc);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(210, 310, 161, 31));
        med_name = new QLineEdit(Timthuoc);
        med_name->setObjectName(QString::fromUtf8("med_name"));
        med_name->setGeometry(QRect(250, 70, 151, 26));

        retranslateUi(Timthuoc);

        QMetaObject::connectSlotsByName(Timthuoc);
    } // setupUi

    void retranslateUi(QDialog *Timthuoc)
    {
        Timthuoc->setWindowTitle(QCoreApplication::translate("Timthuoc", "SEARCHMED", nullptr));
        label_2->setText(QCoreApplication::translate("Timthuoc", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">ENTER MEDICINE NAME</span></p></body></html>", nullptr));
        find->setText(QCoreApplication::translate("Timthuoc", "FIND", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("Timthuoc", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:600; color:#0000ff;\">MEDICINE STORE</span></p></body></html>", nullptr));
        update->setText(QCoreApplication::translate("Timthuoc", "UPDATE", nullptr));
        med_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Timthuoc: public Ui_Timthuoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMTHUOC_H
