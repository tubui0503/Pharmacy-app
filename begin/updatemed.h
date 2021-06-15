#ifndef UPDATEMED_H
#define UPDATEMED_H

#include <QDialog>

namespace Ui {
class Updatemed;
}

class Updatemed : public QDialog
{
    Q_OBJECT

public:
    explicit Updatemed(QWidget *parent = nullptr);
    ~Updatemed();

private slots:
    void on_update_bt_clicked();

private:
    Ui::Updatemed *ui;
};

#endif // UPDATEMED_H
