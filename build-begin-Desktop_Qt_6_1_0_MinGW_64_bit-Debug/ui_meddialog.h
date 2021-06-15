/********************************************************************************
** Form generated from reading UI file 'meddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDDIALOG_H
#define UI_MEDDIALOG_H

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

class Ui_MedDialog
{
public:
    QTableWidget *table_1;
    QPushButton *find_2;
    QLineEdit *mednum;
    QLabel *kho_thuoc;

    void setupUi(QDialog *MedDialog)
    {
        if (MedDialog->objectName().isEmpty())
            MedDialog->setObjectName(QString::fromUtf8("MedDialog"));
        MedDialog->resize(457, 479);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MedDialog->setWindowIcon(icon);
        table_1 = new QTableWidget(MedDialog);
        table_1->setObjectName(QString::fromUtf8("table_1"));
        table_1->setGeometry(QRect(10, 120, 431, 331));
        find_2 = new QPushButton(MedDialog);
        find_2->setObjectName(QString::fromUtf8("find_2"));
        find_2->setGeometry(QRect(360, 40, 80, 25));
        QFont font;
        font.setBold(true);
        find_2->setFont(font);
        mednum = new QLineEdit(MedDialog);
        mednum->setObjectName(QString::fromUtf8("mednum"));
        mednum->setGeometry(QRect(210, 40, 131, 24));
        kho_thuoc = new QLabel(MedDialog);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(0, 40, 191, 31));
        QFont font1;
        font1.setPointSize(7);
        kho_thuoc->setFont(font1);

        retranslateUi(MedDialog);

        QMetaObject::connectSlotsByName(MedDialog);
    } // setupUi

    void retranslateUi(QDialog *MedDialog)
    {
        MedDialog->setWindowTitle(QCoreApplication::translate("MedDialog", "SEARCH", nullptr));
        find_2->setText(QCoreApplication::translate("MedDialog", "FIND", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("MedDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#0000ff;\">MEDICINE CODE</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedDialog: public Ui_MedDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDDIALOG_H
