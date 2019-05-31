#ifndef PRUEBA_H
#define PRUEBA_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class Prueba;
}

class Prueba : public QDialog
{
    Q_OBJECT

public:
    explicit Prueba(QWidget *parent = nullptr);
    ~Prueba();

    //virtual void paintEvent(QPaintEvent *e);//constructor del cuadrito
//    virtual void paintEvent2(QPaintEvent *e);//constructor del cuadrito

    void nuevoCuadro(Prueba*,int,int);
    void generarMatriz(int size);

private:
    Ui::Prueba *ui;
};

#endif // PRUEBA_H
