#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>

namespace Ui {
class window;
}

class window : public QDialog
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = nullptr);
    ~window();

private slots:
    void on_Accept_clicked();

    void on_Cancel_clicked();

private:
    Ui::window *ui;
};

#endif // WINDOW_H
