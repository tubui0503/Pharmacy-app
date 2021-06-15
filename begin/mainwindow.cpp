#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "search.h"
#include "timthuoc.h"

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

struct thuoc{
    int key;
    string name;
    int price;
    int amount;
    int amount_buy;
    int sum;
};

struct loaithuoc{
    int key;
    string name;
    string donvi;
    int price;
    int amount;
    string day;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    QStringList tde={"Name","Amount","Price(VND)"};
    mModel->setHorizontalHeaderLabels(tde);
    ui->tableView->setModel(mModel);
    setWindowTitle("Customer Information");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setValueAt(int ix, int jx, const QString &value)
{
  if (!mModel->item(ix,jx)){
      mModel->setItem(ix,jx, new QStandardItem(value));
  }
  else{
       mModel->item(ix,jx)->setText(value);
  }
}

QString MainWindow::getValueAt(int ix, int jx)
{
    if(!mModel->item(ix,jx)){
        return "";
    }
    return mModel->item(ix,jx)->text();
}



int MainWindow::getRowCount() const
{
    return ui->CountThuoc->value();
}

int MainWindow::getColCount() const
{
    return 3;
}

void inc_quickSort(int a[], int l, int r){
   int p = a[(l+r)/2]; //trung điểm
   int i = l, j = r;
   while (i < j){
       while (a[i] < p){
           i++;
       }
       while (a[j] > p){
           j--;
       }
       if (i <= j){
           int temp = a[i];
           a[i] = a[j];
           a[j] = temp;
           i++;
           j--;
       }
   }
   if (i < r){
       inc_quickSort(a, i, r);
   }
   if (l < j){
       inc_quickSort(a, l, j);
   }
}

//tìm kiếm
int Bin_search(int a[], int n, int x){ //search nhi phan
    int l = 0, r = n-1;
    while (l < r){
        int mid = (l+r)/2;
        if (a[mid] < x){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    if (a[l] == x){
        return l;
    }
    return -1;
}
bool tim_so(int &madt){
    QString filetxt_madonthuoc=QDir::currentPath();
    QDir dir ("thongtinKH");
    if (!dir.exists()){
        QDir().mkdir("thongtinKH");
    }
    filetxt_madonthuoc.append("/thongtinKH/madonthuoc.txt");
    QFile file_txt(filetxt_madonthuoc);
    if ( !file_txt.open(QFile::ReadOnly | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
            QTextStream in(&file_txt);
            while (!in.atEnd())
        { auto line = in.readLine();
          auto values= line.split(',');
          int m=values.size();
          cout<<m;

          int *arr = new int(m);
          for(int i=0;i<m;i++)
             {  arr[i]=values.at(i).toInt();}
          inc_quickSort(arr, 0, m-1);
          if(Bin_search(arr, m , madt)==-1)
        {
            cout<<"Khong tim thay phan tu trong mang"<<endl; //nếu ko tìm thấy
            delete arr;
            return false;
          }
          else{
          cout<<"Tim thay phan tu tai vi tri thu "<<Bin_search(arr, m , madt)<<" trong mang"<<endl;
          delete arr;
          return true;
          }

         }
         }
    file_txt.flush();
    file_txt.close();
    return false;
}

int read_file1(string key,thuoc &med)
{
    QString med_dir=QDir::currentPath();
    med_dir.append("/khothuoc/");
    QString fileTail=".csv";
    QString key1=QString::fromUtf8(key);
    key1.append(fileTail);
    med_dir.append(key1);
    QFile file(med_dir);
    string test=med_dir.toUtf8().constData();
    cout<<endl<<test<<endl;
    //QFile file("F:/Giaithuat_cautruc/GUI/Quanly_KH/Med.csv");
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        // Create a thread to retrieve data from a file
        QTextStream in(&file);
        //Reads the data up to the end of file
        while (!in.atEnd())
    { auto line = in.readLine();
      QStringList values1;
      values1 = line.split(",");
      med.name = values1.at(1).toUtf8().constData();
      if(key==med.name)
      {   med.key = values1.at(0).toInt();
          med.price = values1.at(3).toInt();
          med.amount = values1.at(4).toInt();
          if(med.amount==0)
          {
              cout<<"Thuoc da het!!";
              return 0;
          }
          else
          {   cout<<"Tim thay thuoc";
              return 1;
          }
      }
      else
      {
          cout<<"Khong tim thay thuoc";
          continue;
      }

   }
   file.flush();
   file.close();
}
    return 0;
}

int flag;
void MainWindow::on_btn_donthuoc_clicked()
{
    const int rowCount=getRowCount();
    const int colCount=getColCount();
    mModel->setRowCount(rowCount);
    mModel->setColumnCount(colCount);
    int addmed = ui->CountThuoc->value();
    if(addmed==0) flag=0;
    else flag=1;

}
bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}


void MainWindow::on_update_clicked()
{
    //Lay thong so hang va cot tu spinBox khi setup so thuoc
    const int rowCount= mModel->rowCount();
    const int colCount= mModel->columnCount();
    int num=0;
    int sum=0;
    string name;
    vector <thuoc> med;
    //Luu thong tin tung o cua table vao 1 hang trong file thongtinthuoc.csv
    for (int ix=0;ix<rowCount;++ix){
        thuoc temp;
        QString med_name = getValueAt(ix,0);
        name=med_name.toUtf8().constData();//tenthuoc
        temp.name=name;  //tenthuoc
        for(int jx=1;jx<colCount-1;++jx){
            QString med_num = getValueAt(ix,jx);
            num = med_num.toInt();//soluong
            temp.amount_buy=num;//soluong
            int test=read_file1(name,temp);
            if(test==0)
            {
                       QMessageBox messageBox;
                       std::string message ="Out of " + name;
                       messageBox.information( 0, "ERROR", message.c_str() );
                       return;
            }
            sum=num*temp.price;
            temp.sum=sum;
            med.push_back(temp);
        }
    }
    //cap nhat len table
     int sum_med=0;
    for (int ix=0;ix<rowCount;++ix)
    {   QString name1=QString::fromUtf8(med[ix].name);
        QString num1=QString ::number(med[ix].amount_buy);
        QString sum1=QString ::number(med[ix].sum);
        sum_med=sum_med+med[ix].sum;
        setValueAt(ix,0,name1);
        for(int jx=1;jx<colCount;++jx)
        {
            if(jx==1) setValueAt(ix,jx,num1);
            if(jx==2) setValueAt(ix,jx,sum1);
        }
    }
    cout<<endl<<sum_med<<endl;
    ui->sum->display(sum_med);
    return;
}

void MainWindow::on_themmoi_clicked()
{
    if(ui->hoten->text().isEmpty() || ui->sdt->text().isEmpty() || ui->comboBox->currentText()=="")
  {            QMessageBox::information(
                  this,
                  tr("ERROR"),
                  tr("Please enter customer information!!!"));
                  return;
    }
    //file thong tin cac don thuoc
    int letters=0;
    int numb=0;
    QString sdt_bn = ui->sdt->text();
    foreach(QChar s, sdt_bn) {
       if (s.isLetter()) {
          letters++;}
    }
    if (letters>0){
        sdt_bn.clear();
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Wrong Phone number, please type again") );

        return;
    }

    QString ID = ui->sdt->text();//sdt kh
    string ID1=ID.toUtf8().constData();
    if(ID1.size()!=10)
    {
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Wrong Phone number, please type again") );

        return;
    }
    QString line_hoten = ui->hoten->text();//ten kh
    foreach(QChar s1, line_hoten) {
       if (s1.isDigit()) {
          numb++;}
    }
    if (numb>0){
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Wrong Name, please type again") );
        return;
    }

    int addmed = ui->CountThuoc->value();
    if((addmed*flag) == 0)
    {
        QMessageBox::information(
            this,
            tr("Warning"),
            tr("Please add medicine!!") );
        return;
    }
    QDate date = QDate::currentDate();//ngay lap don
    QString date1=date.toString();
    QString line_gioitinh = ui->comboBox->currentText();//gioitinh
    string t = ID.toUtf8().constData();//doi sdt tu string sang int
    int t1=t[6]-48;
    int t2=t[7]-48;
    int t3=t[8]-48;
    int t4=t[9]-48;
    int key=t1*1000+t2*100+t3*10+t4;//lay 4 so cuoi cua so dt

    //random 1 so
    int number = rand() % 9000 + 1000;
    while(tim_so(number)==true){
         number = rand() % 9000 + 1000;
    }
    QString filetxt_madonthuoc=QDir::currentPath();
    filetxt_madonthuoc.append("/thongtinKH/madonthuoc.txt");
    QFile file_txt(filetxt_madonthuoc);
    if (!file_txt.open(QIODevice::WriteOnly|QIODevice::Append |QIODevice::Text)){
        QMessageBox::warning(this,"Message","File madonthuoc.txt can not open!!!");
    }
    else{
    //file_txt.open(QIODevice::ReadWrite| QIODevice::Append);
    QApplication::processEvents();
    QTextStream out(&file_txt);
    out<<number<<",";
    file_txt.flush();
    file_txt.close();
    }
    //Lay thong so hang va cot tu spinBox khi setup so thuoc
    const int rowCount= mModel->rowCount();
    const int colCount= mModel->columnCount();
    vector <thuoc> med;
    int sum_med=0;

    //Luu thong tin tung o cua table vao 1 hang trong file thongtinthuoc.csv
    for (int ix=0;ix<rowCount;++ix){
        thuoc temp;
        QString med_name = getValueAt(ix,0);
        string name=med_name.toUtf8().constData();//tenthuoc
        temp.name=name;  //tenthuoc
        for(int jx=1;jx<colCount-1;++jx){
            QString med_num = getValueAt(ix,jx);
            int num = med_num.toInt();
            temp.amount_buy=num;
            read_file1(name,temp);
            int sum=num*temp.price;
            temp.sum=sum;
            med.push_back(temp);
        }
    }
    for(int i=0;i<rowCount;i++)
    {
        sum_med=sum_med+med[i].sum;//tong tien
    }

    //mo file thongtinthuoc.csv (file nay chua tat ca thong tin cac don thuoc ma cac KH da mua)
    QString filecsv_thongtinthuoc= QDir::currentPath();
    //neu chua co folder thongtinthuoc thi tao ra folder nay
    QDir dir1 ("thongtinthuoc");
    if (!dir1.exists()){
        QDir().mkdir("thongtinthuoc");
    }
    filecsv_thongtinthuoc.append("/thongtinthuoc/thongtinthuoc.csv");
    QFile file(filecsv_thongtinthuoc);
    if(!file.open(QIODevice::ReadWrite|QIODevice::Append |QIODevice::Text)){
        printf("can't not open file thongtinthuoc.csv");
        return;
    }
    else{
//    file.open(QIODevice::ReadWrite| QIODevice::Append);
    //thong tin donthuoc
    QApplication::processEvents();
    QTextStream xout(&file);
    //Neu file co data thi xuong dong roi ghi du lieu tiep theo vao.
    if (file.pos() != 0) {
       xout<<"\n";// some data inside
    }
    xout<<number<<",";
    xout<<rowCount<<",";
    for(int i=0;i<rowCount;i++)
    {   QString key = QString::number(med[i].key);
        xout<<key<<",";
        QString name = QString::fromUtf8(med[i].name);
        xout<<name<<",";
        QString amount_buy = QString::number(med[i].amount_buy);
        xout<<amount_buy<<",";
        QString price = QString::number(med[i].price);
        xout<<price<<",";
    }
    //dong file khi luu xong
    file.flush();
    file.close();
    }

    //thong tin KH
    QString filecsv_mabn= QDir::currentPath();
    filecsv_mabn.append("/thongtinKH/");
    QString fileTail=".csv";
    QString phone=QString ::number(key);
    sdt_bn.append(fileTail);
    filecsv_mabn.append(sdt_bn);
    QFile file1(filecsv_mabn);
    if(!file1.open(QIODevice::WriteOnly|QIODevice::Append |QIODevice::Text)){
        printf("can't not open file");
        return;
    }
    else{
    QString tongtien = QString::number(sum_med);
    //file1.open(QIODevice::ReadWrite| QIODevice::Append);

    if (file1.pos() == 0) {
      // is empty
        QApplication::processEvents();
        QTextStream xout1(&file1);
        xout1<<phone<<","<<line_hoten<<","<<
               line_gioitinh<<","<<number<<","<<tongtien<<","<<date1<<",";
    }
    else
    {
      // some data inside
        QApplication::processEvents();
        QTextStream xout1(&file1);
        xout1<<number<<","<<tongtien<<","<<date1<<",";
    }
    file1.flush();
    file1.close();
    }
    //cap nhat lai kho thuoc
    for(int i=0;i<rowCount;i++)
    {
        QString med_dir=QDir::currentPath();
        med_dir.append("/khothuoc/");
        QString key1=QString::fromUtf8(med[i].name);
        key1.append(fileTail);
        med_dir.append(key1);

        QFile file2(med_dir);
        QTextStream in(&file2);
        QTextStream xout2(&file2);
        string test=med_dir.toUtf8().constData();
        cout<<endl<<test<<endl;
        loaithuoc temp1;
        if ( !file2.open(QFile::ReadWrite | QFile::Text) ) {
            qDebug() << "File not exists";
        } else {
                    while (!in.atEnd())
                    {
                        //doc file
                        auto line = in.readLine();
                        QStringList values1;
                        values1 = line.split(",");
                        temp1.key = values1.at(0).toInt();
                        temp1.name = values1.at(1).toUtf8().constData();
                        temp1.donvi = values1.at(2).toUtf8().constData();
                        temp1.price = values1.at(3).toInt();
                        temp1.amount = values1.at(4).toInt();
                        temp1.day = values1.at(5).toUtf8().constData();
                     }

                    file2.flush();
                    file2.close();
                        //ghi de

                    if ( !file2.open(QFile::ReadWrite | QFile::Text) ) {
                        qDebug() << "File not exists";
                    } else {

                                    QString key = QString::number(temp1.key);
                                    xout2<<key<<",";
                                    QString name = QString::fromUtf8(temp1.name);
                                    xout2<<name<<",";
                                    QString donvi = QString::fromUtf8(temp1.donvi);
                                    xout2<<donvi<<",";
                                    QString price = QString::number(temp1.price);
                                    xout2<<price<<",";
                                    temp1.amount= temp1.amount-med[i].amount_buy;
                                    QString amount = QString::number(temp1.amount);
                                    xout2<<amount<<",";
                                    QString day = QString::fromUtf8(temp1.day);
                                    xout2<<day<<",";

                            }
                    file2.flush();
                    file2.close();
    }

}
    QMessageBox::information(
                     this,
                     tr("MEDAPP"),
                     tr("Thank you!!!"));
                     return;
}



void MainWindow::on_search_clicked()
{
    Search find;
    find.setModal(true);
    find.exec();
}

void MainWindow::on_med_clicked()
{
    Timthuoc medFind;
    medFind.setModal(true);
    medFind.exec();
}

