#ifndef MYTIMER_H
#define MYTIMER_H
#include <QtCore>
#include <QTimer>
#include <QGraphicsScene>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    QGraphicsTextItem *texto;
    MyTimer(/*QObject *parent=NULL*/ );
    QTimer *timer;
    int playtime = 20;
    void modifyTime(int timeAdded);

    int getPlaytime();
    void setPlaytime(int value);

public slots:
    void MySlot();
};

#endif // MYTIMER_H
