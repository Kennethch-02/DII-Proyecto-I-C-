#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QTcpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Connect();
    void Send_Message();

private slots:
    void on_BTN_RUN_clicked();

    void on_BTN_STOP_clicked();

    void on_BTN_NEXT_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *mSocket;
};
#endif // MAINWINDOW_H
