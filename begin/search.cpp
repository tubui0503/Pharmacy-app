#include "search.h"
#include "ui_search.h"
#include "meddialog.h"
#include "mainwindow.h"

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
#include <QDir>
#include <QLineEdit>
#include <sstream>
using namespace std;
struct MED
{
    int key_med;
    double price;
    string day;

};

struct KH
{
    int cnt_med;
    vector <MED> key_med;
    string Fullname;
    string gender;
    int phone;
};

#define MAX 1000
KH *hashTable= new KH[MAX]; //bang bam
int hashTableSize = MAX;

int hashFunc(int x)
{
    return (x%hashTableSize);
}

int insert_hash(int x) //Linear probing
{
    //Compute the index using the hash function
    int index = hashFunc(x);
    //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index].phone != 0)
        index = (index + 1);
    //get_data(hashTable[index]);
    return index;
}

int search_hash(int y)
{
    //Compute the index using the hash function
    int index = hashFunc(y);
     //Search for an unused slot and if the index will exceed the hashTableSize then roll back
    while(hashTable[index].phone != y and hashTable[index].phone != 0)
    {     index = (index + 1);}
    //Check if the element is present in the hash table
    if(hashTable[index].phone == y)
    {   cout<<"Ho va ten: "<<hashTable[index].Fullname<<endl;
        cout<<"Gioi tinh: "<<hashTable[index].gender<<endl;
        cout<<"So dien thoai: "<<hashTable[index].phone<<endl;
        cout<<"Don thuoc da mua: "<<endl;
        for(int i=0;i<hashTable[index].cnt_med;i++)
        {
            cout<<hashTable[index].key_med[i].key_med<<endl;
            cout<<hashTable[index].key_med[i].price<<endl;
            cout<<hashTable[index].key_med[i].day<<endl;
        }
    }
    else
    {cout<<"No Information!\n";
        return 0;}
    return index;
}

void read_file(QString &filename)
{
    int key;
    QFile file(filename);
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        // Create a thread to retrieve data from a file
        QTextStream in(&file);
        //Reads the data up to the end of file
        while (!in.atEnd())
    { auto line = in.readLine();
      auto values= line.split(',');
      key = values.at(0).toInt();
      int index = insert_hash(key);
      int t= values.size();
      //insert data to hashtable
      hashTable[index].phone=key;
      hashTable[index].Fullname = values.at(1).toUtf8().constData();
      hashTable[index].gender = values.at(2).toUtf8().constData();
      t=(t-3)/3;
      hashTable[index].cnt_med =t;
      for(int i=0;i<hashTable[index].cnt_med;i++)
      {   MED temp;
          temp.key_med = values.at(3+3*i).toInt();
          temp.price = values.at(4+3*i).toInt();
          temp.day = values.at(5+3*i).toUtf8().constData();
          hashTable[index].key_med.push_back(temp);
      }
   }
   file.flush();
   file.close();
}

}
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    ui->phonenum->setInputMask("9999999999");
}

Search::~Search()
{
    delete ui;
}

void Search::on_find_clicked()
{
    if(ui->phonenum->text().isEmpty())
        {            QMessageBox::information(
                        this,
                        tr("ERROR"),
                        tr("Please type phone number!!!"));
                        return;
        }
            QString key1= ui->phonenum->text();
            string t = key1.toUtf8().constData();
            int t1=t[6]-48;
            int t2=t[7]-48;
            int t3=t[8]-48;
            int t4=t[9]-48;
            int key=t1*1000+t2*100+t3*10+t4;
            QString ID =key1;
            QString fileTail=".csv";
            ID.append(fileTail);
            QString filename= QDir::currentPath();
            filename.append("/thongtinKH/");
            filename.append(ID);
            read_file(filename);
            int index=search_hash(key);
            if(index==0)
            {
                QMessageBox::information(
                    this,
                    tr("ERROR"),
                    tr("No Information!!!") );
                return;
            }
            //create table
            ui->table->setRowCount(hashTable[index].cnt_med);
            ui->table->setColumnCount(3);

            QStringList hlabels;
            hlabels <<"MED CODE"<<"PRICE"<<"DATE";
            ui->table->setHorizontalHeaderLabels(hlabels);
            //insert data
            QString name = QString::fromUtf8(hashTable[index].Fullname);
            QString gender = QString::fromUtf8(hashTable[index].gender);
            ui->fullname->setText(name);
            ui->gender->setText(gender);
            for(int i=0;i<ui->table->rowCount();i++)
            {   QTableWidgetItem *item;
                for(int j=0;j<ui->table->columnCount();j++)
                { item = new QTableWidgetItem;
                  if(j==0)
                  {   QString bill = QString::number(hashTable[index].key_med[i].key_med);
                      item->setText(bill);
                  }
                  if(j==1)
                  {   QString price = QString::number(hashTable[index].key_med[i].price);
                      item->setText(price);}
                  if(j==2)
                  {   QString day = QString::fromUtf8(hashTable[index].key_med[i].day);
                      item->setText(day);}
                  ui->table->setItem(i,j,item);
                }
            }
            return;
}


void Search::on_find_med_clicked()
{
    MedDialog medDialog;
    medDialog.setModal(true);
    medDialog.exec();
}

