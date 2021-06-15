#ifndef MEDDIALOG_H
#define MEDDIALOG_H

#include <QDialog>

namespace Ui {
class MedDialog;
}

class MedDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MedDialog(QWidget *parent = nullptr);
    ~MedDialog();

private slots:
    void on_find_2_clicked();


private:
    Ui::MedDialog *ui;
};

#endif // MEDDIALOG_H
