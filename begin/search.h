#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = nullptr);
    ~Search();

private slots:
    void on_find_clicked();

    void on_find_med_clicked();



private:
    Ui::Search *ui;
};

#endif // SEARCH_H
