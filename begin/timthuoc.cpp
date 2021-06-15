#include "timthuoc.h"
#include "ui_timthuoc.h"
#include "updatemed.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QLineEdit>
#include <QDir>

using namespace std;
struct Thuoc
{   int ma_thuoc;
    string ten_thuoc;
    string don_vi;
    long int gia;
    int so_luong;
    string ngay;
};
typedef struct Thuoc KT;

#define MAX 100
KT *Table1= new KT[MAX]; //bang
int TableSize1 = MAX;

int read_file1(string name)
{
    QString kho_thuoc =QDir::currentPath();
    kho_thuoc.append("/khothuoc/");
    QString key1=QString ::fromUtf8(name);
    QString fileTail=".csv";
    key1.append(fileTail);
    kho_thuoc.append(key1);
    QFile file(kho_thuoc);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
        return 0;
    } else {
        // Create a thread to retrieve data from a file
        QTextStream in(&file);
        //Reads the data up to the end of file
        while (!in.atEnd())
    { auto line = in.readLine();
      string s = line.toUtf8().constData();
      cout<<s<<endl;
      QStringList values1;
      values1 = line.split(",");
          Table1[0].ma_thuoc = values1.at(0).toInt();
          Table1[0].ten_thuoc = values1.at(1).toUtf8().constData();
          Table1[0].don_vi = values1.at(2).toUtf8().constData();
          Table1[0].gia = values1.at(3).toInt();
          Table1[0].so_luong = values1.at(4).toInt();
          Table1[0].ngay = values1.at(5).toUtf8().constData();
        }

   }
   file.flush();
   file.close();
   return 1;
}


Timthuoc::Timthuoc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timthuoc)
{
    ui->setupUi(this);
}

Timthuoc::~Timthuoc()
{
    delete ui;
}

void Timthuoc::on_find_clicked()
{
    if(ui->med_name->text().isEmpty())
    {            QMessageBox::information(
                  this,
                  tr("ERROR"),
                  tr("Please enter medicine name!!!"));
                  return;
    }
      QString key1= ui->med_name->text();
      string key = key1.toUtf8().constData();
      cout<<key<<endl;
      int index = read_file1(key);
      if(index==0)
      {
          QMessageBox::information(
              this,
              tr("ERROR"),
              tr("No Information!!!"));
          return;
      }
      cout<<index;
      //create table
      ui->table->setRowCount(1);
      ui->table->setColumnCount(6);
      QStringList hlabels;
      hlabels <<"Medicine Code"<<"Medicine Name"<<"Unit"<<"Amount"<<"Price"<<"Day Add";
      ui->table->setHorizontalHeaderLabels(hlabels);
      //insert data to table
       for(int i=0;i<ui->table->rowCount();i++)
       {
           QTableWidgetItem *item;
          for(int j=0;j<ui->table->columnCount();j++)
          { item = new QTableWidgetItem;
            if(j==0)
            {   QString ma = QString::number(Table1[0].ma_thuoc);
                item->setText(ma);}
            if(j==1)
            {   QString ten = QString::fromUtf8(Table1[0].ten_thuoc);
                item->setText(ten);}
            if(j==2)
            {   QString dv = QString::fromUtf8(Table1[0].don_vi);
                item->setText(dv);}
            if(j==3)
            {   QString sl = QString::number(Table1[0].so_luong);
                item->setText(sl);}
            if(j==4)
            {   QString gt = QString::number(Table1[0].gia);
                item->setText(gt);}
            if(j==5)
            {    QString day = QString::fromUtf8(Table1[0].ngay);
                item->setText(day);}
            ui->table->setItem(i,j,item);
          }
      }
       return;
}


void Timthuoc::on_update_clicked()
{
    Updatemed medUpdate;
    medUpdate.setModal(true);
    medUpdate.exec();
}




