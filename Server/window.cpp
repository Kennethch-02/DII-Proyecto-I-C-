#include "window.h"
#include "ui_window.h"
#include "server.h"

window::window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);
}

window::~window()
{
    delete ui;
}

void window::on_Accept_clicked()
{
    server Server;
    if (!Server.startServer(ui->port->value())){
        qDebug()<< Server.errorString();
    }else{
        Server.memory = ui->memory->value();
        qDebug()<<"Servidor Iniciado";
    }
    accept();
}
void window::on_Cancel_clicked()
{
    reject();
}
