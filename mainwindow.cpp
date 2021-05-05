#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "message.h"
#include "json.h"
#include <QTcpSocket>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        ui->CMD_TEXT->append(text);
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Connect(){
    mSocket->connectToHost("localhost", 1234);
}
void MainWindow::Send_Message(){
    QTextStream A(mSocket);
    message M;
    json J;
    M.setAction("HOLA");
    M.setType("Notting");
    M.setData("AAA");
    QJsonArray array {J.Parse(M)};
    QJsonDocument jsDoc(array);
    QString a = QString::fromLatin1(jsDoc.toJson());
    A<<a;
    A.flush();
}
void MainWindow::on_BTN_RUN_clicked()
{
    Send_Message();
}
void MainWindow::on_BTN_STOP_clicked()
{

}
void MainWindow::on_BTN_NEXT_clicked()
{

}
