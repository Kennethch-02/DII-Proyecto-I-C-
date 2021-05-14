#include "mserver.h"
#include "ui_mserver.h"
#include "dialog.h"
#include "QThread"
#include <thread>
mserver::mserver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mserver)
{
    ui->setupUi(this);
}

mserver::~mserver()
{
    delete ui;
}
void mserver::on_Connect_clicked()
{
    Dialog m(this);
    if(m.exec() == QDialog::Rejected){
        return;
    }else{
        if(Server.startServer(m.port)){
            Server.memory = m.memory;
            QString a;
            Server.CMD.append("Started Server: Port: "+ QString::number(m.port));
            ui->Status->setText("Connected");
            ui->Connect->setDisabled(true);
            Thread();
        }else{
            Server.CMD.append("Erorr: "+Server.errorString());
        }
    }
}
void mserver::Thread(){
   ui->CMD->setText(Server.CMD);
}
