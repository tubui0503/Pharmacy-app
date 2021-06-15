/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QPushButton *find;
    QTextBrowser *gender;
    QLineEdit *phonenum;
    QTextBrowser *fullname;
    QTableWidget *table;
    QPushButton *find_med;
    QLabel *kho_thuoc;
    QLabel *kho_thuoc_2;
    QLabel *kho_thuoc_3;

    void setupUi(QDialog *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QString::fromUtf8("Search"));
        Search->resize(400, 466);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/Icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Search->setWindowIcon(icon);
        find = new QPushButton(Search);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(140, 390, 101, 41));
        QFont font;
        font.setBold(true);
        find->setFont(font);
        gender = new QTextBrowser(Search);
        gender->setObjectName(QString::fromUtf8("gender"));
        gender->setGeometry(QRect(120, 80, 61, 41));
        gender->setFont(font);
        gender->setFrameShape(QFrame::WinPanel);
        gender->setFrameShadow(QFrame::Plain);
        phonenum = new QLineEdit(Search);
        phonenum->setObjectName(QString::fromUtf8("phonenum"));
        phonenum->setGeometry(QRect(100, 350, 191, 24));
        phonenum->setMaxLength(10);
        fullname = new QTextBrowser(Search);
        fullname->setObjectName(QString::fromUtf8("fullname"));
        fullname->setGeometry(QRect(120, 20, 181, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        fullname->setFont(font1);
        fullname->setFrameShape(QFrame::WinPanel);
        fullname->setFrameShadow(QFrame::Plain);
        table = new QTableWidget(Search);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(20, 130, 371, 171));
        find_med = new QPushButton(Search);
        find_med->setObjectName(QString::fromUtf8("find_med"));
        find_med->setGeometry(QRect(310, 90, 81, 31));
        find_med->setFont(font);
        kho_thuoc = new QLabel(Search);
        kho_thuoc->setObjectName(QString::fromUtf8("kho_thuoc"));
        kho_thuoc->setGeometry(QRect(30, 20, 71, 41));
        QFont font2;
        font2.setPointSize(7);
        kho_thuoc->setFont(font2);
        kho_thuoc_2 = new QLabel(Search);
        kho_thuoc_2->setObjectName(QString::fromUtf8("kho_thuoc_2"));
        kho_thuoc_2->setGeometry(QRect(0, 70, 101, 41));
        kho_thuoc_2->setFont(font2);
        kho_thuoc_3 = new QLabel(Search);
        kho_thuoc_3->setObjectName(QString::fromUtf8("kho_thuoc_3"));
        kho_thuoc_3->setGeometry(QRect(100, 300, 191, 41));
        kho_thuoc_3->setFont(font2);

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QDialog *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "SEARCH", nullptr));
        find->setText(QCoreApplication::translate("Search", "FIND", nullptr));
        find_med->setText(QCoreApplication::translate("Search", "FIND_MED", nullptr));
        kho_thuoc->setText(QCoreApplication::translate("Search", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#0000ff;\">NAME</span></p></body></html>", nullptr));
        kho_thuoc_2->setText(QCoreApplication::translate("Search", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#0000ff;\">GENDER</span></p></body></html>", nullptr));
        kho_thuoc_3->setText(QCoreApplication::translate("Search", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#0000ff;\">PHONE NUMBER</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
