#include "prueba.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Prueba w;
    w.show();

    return a.exec();
}
