#include "prueba.h"
#include "ui_prueba.h"
#include <iostream>

using namespace std;
Prueba::Prueba(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prueba)
{
    ui->setupUi(this);
    this->generarMatriz(5);
}

Prueba::~Prueba()
{
    delete ui;
}



void Prueba::generarMatriz(int size){
    Prueba::nuevoCuadro(this,1,1);

}


void Prueba::nuevoCuadro(Prueba *ventana,int cordX,int cordY){
    for(int i=20;i<=200;i+=20){
         for(int c=20;c<=200;c+=20){


            QPainter *painter=new QPainter(this);
            painter->setBrush(Qt::green);
            painter->drawRect(QRect(i*2,c*2,20,20));

        }
    }

    for(int i=30;i<=200;i+=20){
         for(int c=30;c<=200;c+=20){
            QPainter *painters=new QPainter(this);
            painters->setBrush(Qt::red);
            painters->drawRect(QRect(i*2,c*2,20,20));

        }
    }
}

//void Prueba::paintEvent(QPaintEvent *e){ //recibe una cordenada x y, y crea el objeto
//    for(int i=20;i<=200;i+=20){
//         for(int c=20;c<=200;c+=20){


//            QPainter *painter=new QPainter(this);
//            painter->setBrush(Qt::green);
//            painter->drawRect(QRect(i*2,c*2,20,20));

//    }
//    }

//    for(int i=30;i<=200;i+=20){
//         for(int c=30;c<=200;c+=20){
//            QPainter *painters=new QPainter(this);
//            painters->setBrush(Qt::red);
//            painters->drawRect(QRect(i*2,c*2,20,20));

//    }
//    }
//}


