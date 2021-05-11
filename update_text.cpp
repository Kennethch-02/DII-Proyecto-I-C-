#include "update_text.h"

update_text::update_text():QThread()
{

}
void update_text::run()
{
    //Instrucciones
    while (true) {
        QString b;
        if (text != ant_text){
            QStringList a = text.split("\n");
            for (int i = 0; i<a.size(); i++){
                b.append(i);
            }
            emit new_text(b);
            ant_text = text;
        }
    }


}
