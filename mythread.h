#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>

class MyThread : public QThread
{
public:
    MyThread();
    void run();
    //QThread mThread;
};

#endif // MYTHREAD_H
