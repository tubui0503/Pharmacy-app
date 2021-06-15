#include "updatemed.h"
#include "ui_updatemed.h"

#include <QFile>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QApplication>
#include <QLineEdit>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <iostream>
#include <QString>
#include <fstream>
#include <QDebug>
#include <vector>
#include <cstdlib>
#include <QDate>
#include <QDir>
#include <ostream>

using namespace std;
Updatemed::Updatemed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updatemed)
{
    ui->setupUi(this);
    ui->ma_thuoc->setInputMask("9999");
    ui->don_gia->setInputMask("99999999");
    ui->so_luong->setInputMask("99999");
}

Updatemed::~Updatemed()
{
    delete ui;
}

void Updatemed::on_update_bt_clicked()
{
    if(ui->ma_thuoc->text().isEmpty() || ui->ten_thuoc->text().isEmpty() || ui->don_vi->text().isEmpty()
       || ui->don_gia->text().isEmpty() || ui->so_luong->text().isEmpty())
    {            QMessageBox::information(
                  this,
                  tr("ERROR"),
                  tr("Please enter medicine information want to update!!!"));
                  return;
    }
    QString fileTail =".csv";
    QString mathuoc = ui->ma_thuoc->text();
    QString tenthuoc = ui->ten_thuoc->text();
    QString tenthuoc1 = ui->ten_thuoc->text();
    QString donvi = ui->don_vi->text();
    QString dongia = ui->don_gia->text();
    QString soluong = ui->so_luong->text();
    QDate date = QDate::currentDate();//ngay cập nhật
    QString date1=date.toString();

    QString kho_thuoc =QDir::currentPath();
    kho_thuoc.append("/khothuoc/");
    QString key1=tenthuoc;
    key1.append(fileTail);
    kho_thuoc.append(key1);

    QFile file2(kho_thuoc);
    QTextStream xout2(&file2);
    if ( !file2.open(QFile::ReadWrite | QFile::Text) ) {
             return;}
    else {
    string test=kho_thuoc.toUtf8().constData();
    cout<<endl<<test<<endl;
    xout2<<mathuoc<<",";
    xout2<<tenthuoc1<<",";
    xout2<<donvi<<",";
    xout2<<dongia<<",";
    xout2<<soluong<<",";
    xout2<<date1<<",";
    //dong file khi luu xong
    file2.flush();
    file2.close();
    }
    QMessageBox::information(
        this,
        tr("SUCCESS"),
        tr("Update medicine successfully"));
        return;
}

