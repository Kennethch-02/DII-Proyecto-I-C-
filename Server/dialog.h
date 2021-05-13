#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    int Port;
    QString memory;
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_Accept_clicked();

    void on_Cancel_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
