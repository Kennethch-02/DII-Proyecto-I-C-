#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Connect_clicked()
{
    port = ui->port->value();
    memory = ui->memory->value();
    accept();

}

void Dialog::on_Cancel_clicked()
{
    reject();
}
