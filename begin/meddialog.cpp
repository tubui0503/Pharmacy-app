#include "meddialog.h"
#include "ui_meddialog.h"

#include <QDir>
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
#include <QStringList>
using namespace std;

struct Medicine
{   int key_med;
    string name;
    long int price;
    int amount;
};
typedef struct Medicine MD;

struct Prescription
{
    int key;
    int cnt;
    vector <MD> med;
};
typedef struct Prescription PR;
#define MAX 10000
PR *hashTable1= new PR[MAX]; //bang bam
int hashTableSize1 = MAX;

int hashFunc1(int x)
{
    return (x%hashTableSize1);
}

int insert_hash1(int x) //Linear probing
{
    //Compute the index using the hash function
    int index = hashFunc1(x);
    //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable1[index].key != 0)
        index = (index + 1);
    //get_data(hashTable[index]);
    return index;
}

int search_hash1(int y)
{
    //Compute the index using the hash function
    int index = hashFunc1(y);
     //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable1[index].key != y and hashTable1[index].key != 0)
    {     index = (index + 1);}
    //Check if the element is present in the hash table
    if(hashTable1[index].key == y)
    {   cout<<endl<<"Ma don thuoc: "<<hashTable1[index].key<<endl;
        for(int i=0;i<hashTable1[index].cnt;i++)
        {   cout<<"Ma thuoc: "<<hashTable1[index].med[i].key_med<<endl;
            cout<<"Ten thuoc: "<<hashTable1[index].med[i].name<<endl;
            cout<<"So luong: "<<hashTable1[index].med[i].amount<<endl;
            cout<<"So tien moi vien: "<<hashTable1[index].med[i].price<<endl;
         }
    }
    else
    {cout<<"No Information!!\n";
        return 0;}
    return index;
}

void read_file1()
{
    int key;
    QString filecsv_thongtinthuoc= QDir::currentPath();
    //neu chua co folder thongtinthuoc thi tao ra folder nay
    filecsv_thongtinthuoc.append("/thongtinthuoc/thongtinthuoc.csv");
    QFile file(filecsv_thongtinthuoc);
    //QFile file("F:/Giaithuat_cautruc/GUI/Quanly_KH/Med.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
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
      key = values1.at(0).toInt();
      int index = insert_hash1(key);
      //insert data to hashtable
      hashTable1[index].key=key;
      hashTable1[index].cnt = values1.at(1).toInt();
      for(int i=0;i<hashTable1[index].cnt;i++)
      {   MD temp;
          temp.key_med = values1.at(2+4*i).toInt();
          temp.name = values1.at(3+4*i).toUtf8().constData();
          temp.amount = values1.at(4+4*i).toInt();
          temp.price = values1.at(5+4*i).toInt();
          hashTable1[index].med.push_back(temp);
        }

   }
   file.flush();
   file.close();
}
}
MedDialog::MedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MedDialog)
{
    ui->setupUi(this);
    ui->mednum->setInputMask("9999");
}

MedDialog::~MedDialog()
{
    delete ui;
}

void MedDialog::on_find_2_clicked()
{
    if(ui->mednum->text().isEmpty())
  {            QMessageBox::information(
                  this,
                  tr("ERROR"),
                  tr("Please enter medicine code!!!"));
                  return;
  }
      QString key1= ui->mednum->text();
      int key = key1.toInt();
      cout<<key<<endl;
      read_file1();
      int index=search_hash1(key);
      if(index==0)
      {
          QMessageBox::information(
              this,
              tr("ERROR"),
              tr("No Information!!!"));
          return;
      }
      //create table
      ui->table_1->setRowCount(hashTable1[index].cnt);
      ui->table_1->setColumnCount(4);
      QStringList hlabels;
      hlabels <<"Medicine code"<<"Medicine name"<<"Amount"<<"Price/unit(VND)";
      ui->table_1->setHorizontalHeaderLabels(hlabels);
      //insert data to table
      for(int i=0;i<ui->table_1->rowCount();i++)
      {   QTableWidgetItem *item;
          for(int j=0;j<ui->table_1->columnCount();j++)
          { item = new QTableWidgetItem;
            if(j==0)
            {   QString key = QString::number(hashTable1[index].med[i].key_med);
                item->setText(key);}
            if(j==1)
            {   QString name = QString::fromUtf8(hashTable1[index].med[i].name);
                item->setText(name);}
            if(j==2)
            {   QString amount = QString::number(hashTable1[index].med[i].amount);
                item->setText(amount);}
            if(j==3)
            {   QString price = QString::number(hashTable1[index].med[i].price);
                item->setText(price);}
            ui->table_1->setItem(i,j,item);
          }
      }
      return;
}




