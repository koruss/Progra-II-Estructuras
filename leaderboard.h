#ifndef LEADERBOARD_H
#define LEADERBOARD_H
#include "arraylist.h"
#include <QString>




class LeaderBoard{

public:
    ArrayList<QString> *leaderBoard;


    LeaderBoard(){
        this->leaderBoard=new ArrayList<QString>();
    }


    void agregarJugador(QString texto,int score){
        texto.append(" ");
        texto.append(QString::number(score));
        leaderBoard->append(texto);

    }

};

#endif // LEADERBOARD_H
