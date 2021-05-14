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
/**
* \brief Clase que contiene las instrucciones
* e interpretacion del IDE
* @param QApplication
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&](){
        QTextStream T(mSocket);
        auto text = T.readAll();
        received_message = Json.getClass(text);
        Interpreter_Message();
    });
    in_struct = false;
    variables.append("int");
    variables.append("string");
    variables.append("long");
    variables.append("char");
    variables.append("float");
    variables.append("double");
    variables.append("struct");
    variables.append("reference");
    ui->BTN_RUN->setDisabled(true);
    ui->TEXT_CODE->setDisabled(true);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Connect(){
    qDebug()<<port;
    mSocket->connectToHost("localhost", port);
    ui->BTN_RUN->setDisabled(false);
    ui->connect->setDisabled(true);
    ui->port->setDisabled(true);
    ui->ProgressBar->setValue(100);
    ui->APLICATION_LOG->setText("Conectado al servidor");
    ui->TEXT_CODE->setDisabled(false);
}
void MainWindow::Send_Message(){
    QTextStream A(mSocket);
    QJsonArray array {Json.Parse(Message)};
    Message.clear();
    QJsonDocument jsDoc(array);
    QString a = QString::fromLatin1(jsDoc.toJson());
    A<<a;
    A.flush();
}
void MainWindow::Interpreter_Message(){
    if (received_message.type == "RAM"){
        if (received_message.action == "Set"){
            QStringList a = received_message.data.split(" ");
            QString o = a[0];
            ui->RAM_memory->append(o);
            ui->RAM_value->append(a[1]);
            ui->RAM_var->append(a[2]);
            ui->RAM_ref->append(a[3]);
            qDebug()<<ui->RAM_memory->toPlainText();
        }
    }

}
void MainWindow::Interpreter(){
    Line+=1;
    ui->APLICATION_LOG->setText("Interpretando el codigo");
    if (Line == List_size){
        ui->ProgressBar->setValue(100);
    }else{
        ui->ProgressBar->setValue(Line*(100/List_size));
    }
    QString txt_interpreter = List_Code[0];
    txt_interpreter.remove(";");
    //Interpretacion basica del codigo
    ui->TEXT_CODE->append(List_Code[0]);
    ui->TEXT_CODE->selectAll();
    List_Code.pop_front();
    //Interpretacion Avanzada del codigo
    if (txt_interpreter.split(" ")[0] == "int"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();
    }
    if (txt_interpreter.split(" ")[0] == "long"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();

    }
    if (txt_interpreter.split(" ")[0] == "float"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();
    }
    if (txt_interpreter.split(" ")[0] == "double"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();
    }
    if (txt_interpreter.split(" ")[0] == "char"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();
    }
    if (txt_interpreter.split(" ")[0] == "string"){
        Message.type = "Data";
        Message.action = "Set";
        Message.data = txt_interpreter;
        Send_Message();
    }
    if (txt_interpreter.split(" ")[0] == "struct"){
        //estructura adicional

    }
    if (txt_interpreter.split(" ")[0] == "reference"){
        //copia del valor de memoria de <tipo> dato

    }

}
void MainWindow::on_BTN_RUN_clicked()
{
    //Run del codigo, procede a interpretarlo
    Line = 0;
    Code = ui->TEXT_CODE->toPlainText();
    List_Code = Code.split("\n");
    List_size = List_Code.size();
    ui->BTN_RUN->setDisabled(true);
    ui->BTN_NEXT->setDisabled(false);
    ui->BTN_STOP->setDisabled(false);
    ui->TEXT_CODE->clear();
    if (!List_Code.isEmpty()){
        Interpreter();
    }
}
void MainWindow::on_BTN_STOP_clicked()
{
    ui->APLICATION_LOG->setText("En Espera");
    ui->ProgressBar->setValue(100);
    Message.type = "Notify";
    Message.action = "Clear";
    Message.data = "null";
    Send_Message();
    Line = 0;
    ui->TEXT_CODE->setText(Code);
    ui->BTN_RUN->setDisabled(false);
    ui->BTN_STOP->setDisabled(true);
    ui->BTN_NEXT->setDisabled(true);
    ui->RAM_memory->clear();
    ui->RAM_ref->clear();
    ui->RAM_value->clear();
    ui->RAM_var->clear();
}
void MainWindow::on_BTN_NEXT_clicked()
{
    if (!List_Code.isEmpty()){
        Interpreter();
    }
}
void MainWindow::on_TEXT_CODE_textChanged()
{
    //Numera el num line
    QStringList a = ui->TEXT_CODE->toPlainText().split("\n");
    ui->NUM_LINE->clear();
    for(int i = 0; i<a.size(); i++){
        ui->NUM_LINE->append(QString::number(i));
    }
    //Check en vivo del codigo
    int contador = 0;
    bool Correct = false;
    QString tipo;
    QString var = "";
    QString Line;
    in_struct = false;
    for (QString line : a){
        if(line.size() > 0){
            if (line.split(" ")[0] != "//"){
                for (QString str : variables){
                    if (str == line.split(" ")[0]){
                        Correct = true;
                        var = str;
                    }
                }
                if (!Correct and !in_struct){
                    tipo = "invalid type";
                    Line = QString::number(contador);
                    Errors.append("Error: "+tipo+" Line: " + line);              }
                if (var != "struct" and var != "reference" and var != ""){
                    if (!line.endsWith(";")){
                        tipo = "without ;";
                        Line = QString::number(contador);
                        Errors.append("Error: "+tipo+" Line: " + Line);
                    }
                }
                if (var == "struct"){
                    in_struct = true;
                    var = "";
                    if(!line.endsWith("{")){
                        tipo = "without {";
                        Line = QString::number(contador);
                        Errors.append("Error: "+tipo+" Line: " + Line);
                    }
                }
                if (var == "reference"){
                    if (!line.endsWith(";")){
                        tipo = "without ;";
                        Line = QString::number(contador);
                        Errors.append("Error: "+tipo+" Line: " + Line);
                    }
                    else if (line.split(" ").size()>1){
                        QString new_line = line.split(" ")[1];
                        new_line.remove(";");
                        if(!new_line.startsWith("<") or !new_line.endsWith(">")){
                            tipo = "without < >";
                            Line = QString::number(contador);
                            Errors.append("Error: "+tipo+" Line: " + Line);
                        }else{
                            if (new_line.size() == 2){
                                tipo = "without <type>";
                                Line = QString::number(contador);
                                Errors.append("Error: "+tipo+" Line: " + Line);
                            }
                        }
                    }
                }
            }
            if(line[0] == "}" and in_struct){
                if(!line.endsWith(";")){
                    tipo = "without ;";
                    Line = QString::number(contador);
                    Errors.append("Error: "+tipo+" Line: " + line);
                }
                else if(line.endsWith(";")){
                    QStringList a  = line.split(" ");
                    if (a.size() > 1){
                        if(a[1].size() == 1){
                            tipo = "without class";
                            Line = QString::number(contador);
                            Errors.append("Error: "+tipo+" Line: " + line);
                        }else if (a[1].size() > 1){
                            in_struct = false;
                        }
                    }
                    else{
                        tipo = "need use space";
                        Line = QString::number(contador);
                        Errors.append("Error: "+tipo+" Line: " + line);
                    }
                }
            }
            Correct = false;
            contador += 1;
        }
    }
    if(!Errors.isEmpty()){
        ui->APLICATION_LOG->setText(Errors.back());
        ui->BTN_RUN->setDisabled(true);
    }else{
        ui->APLICATION_LOG->setText("Correct");
        ui->BTN_RUN->setDisabled(false);
    }
    Errors.clear();
}

void MainWindow::on_connect_clicked()
{
    port = ui->port->value();
    Connect();
}
