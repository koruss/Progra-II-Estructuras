#ifndef TIMER_H
#define TIMER_H
#include "vista.h"
#include <QTimer>



class Timer:public QObject{
    Q_OBJECT


public:

    Timer(){


        QTimer * timer= new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(changeTxT()));
    }


public slots:
    void changeTxt(){

    }
};

#endif // TIMER_H
