#ifndef UPDATE_TEXT_H
#define UPDATE_TEXT_H

#include <QThread>

class update_text : public QThread
{
    Q_OBJECT
public:
    update_text();
    QString text;
    QString ant_text;
private:
    QString getText();
    QString getAnt_Text();
signals:
    void new_text(QString);
protected:
    void run();
};


#endif // UPDATE_TEXT_H
