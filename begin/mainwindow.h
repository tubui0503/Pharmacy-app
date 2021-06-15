#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QStandardItemModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getRowCount() const;
    int getColCount() const;

private slots:

    void on_btn_donthuoc_clicked();
    void on_themmoi_clicked();

    void on_search_clicked();

    void on_update_clicked();

    void on_med_clicked();

private:
    Ui::MainWindow *ui;
    void hienthi();
    void lis(QString line);
    void setValueAt(int ix, int jx, const QString &value);

    QString getValueAt(int ix,int jx);

    QStandardItemModel *mModel;
};
#endif // MAINWINDOW_H
