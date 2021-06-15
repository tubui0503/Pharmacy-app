#ifndef TIMTHUOC_H
#define TIMTHUOC_H

#include <QDialog>

namespace Ui {
class Timthuoc;
}

class Timthuoc : public QDialog
{
    Q_OBJECT

public:
    explicit Timthuoc(QWidget *parent = nullptr);
    ~Timthuoc();

private slots:
    void on_find_clicked();

    void on_update_clicked();


private:
    Ui::Timthuoc *ui;
};

#endif // TIMTHUOC_H
