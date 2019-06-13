#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>




class Rectangle:public QGraphicsRectItem
{//Herencia de la clase QGraphicsRectItem

private:     //atributos de la clase
    int num;
    Rectangle *up;
    Rectangle *down;
    Rectangle *left;
    Rectangle *right;
    int posX=0;
    int posY=0;
    bool isManzanita;
    bool isFinal;

public:
    Rectangle(){//Constructor inicial

    }

    Rectangle(int posX,int posY){//Este constructor inicializa los atributos y establece el tamanio del rectangulo
        this->posX=posX;
        this->posY=posY;
        setRect(posX,posY,20,20);
        //setFlag(QGraphicsItem::ItemIsFocusable);
        this->up=NULL;
        this->down=NULL;
        this->right=NULL;
        this->left=NULL;
        this->isManzanita=false;
        this->isFinal=false;

    }




    void setKeys(Rectangle *nActual){
        setUp(nActual->getUp());
        setDown(nActual->getDown());
        setLeft(nActual->getLeft());
        setRight(nActual->getRight());

    }







/*
 *                             _
                         .-" `.
                         ;:":  ""--..
                .-+. ,gpd$L\:._      ""-._
               /  //;$SS$$$$SS$$t--.      "-._
             .'  `.//SS$P^"""TS$$S. "-.       "-,
           .'    _ "-S^"      TS$$Sb   "-.       `.
         .'    .':S$Y      _.. SS$$Sb-'   "-.      ;
       .'    .'  SS$;,=-.  ._.`:S$$SS;       j     ;
     .'    .'   :SS$$.-'        SS$$SS\     /     /
   .'     /     SS$$S;    -     SS$$SS ;   /     /
 .'      /   ._dSS$$SS   .--.  :SS$$$S\;  /     /
/       /     :SS$$SS$b. `--'  $$SS$$S ) /     /
\      :      ;SS$$SS$$SS.___.'$$SS$$Sb /     /
 \      "-.   SS$$SS$$$SS      $$SS$$SS';    /
  `.       "-dSS$$SS$$SS:;     :$$SSSP      /
    `.              "^S^':     '^TSS'      /
      "-.      `.     ::-.   _ .-"\\      /
         "-.  -._\    ;;           \\  : :
            "-.   \  ::             \\ ; ;
               $.  `.;;       ,      \\;:
              dS$\  / '-._    :  _.-"" \;
           `-:S$^$t'      ""--:""       ;
              TP :$$ ;        ::        :
                d$S$_:        ;-\       ;
               :$SS$; `.____.'   `.___.j
               $$SS$$                  ;
              / T$S$$;  ;      ;    ; :
             :   `TS$$  :      :    : ;
                   `T$         :     :
                bug  ;         ;     ;
                    /                ;
                  .'                 :
                 /      :           ;:
                /       ;     c     ::
               :`.      ;           : ;
               ;  "-.   :           ; :
              :_     "-.            .' ;
              ; "-.     ""--..__..-"   :
             :     `.                _.-;
             ;       `.           .-"   ;
             ;         `.       .'      ;
             ;           \     /        :
             ;            \   /         :
             ;             \_/          :
             ;             ::           :
             ;             :;           ;
             :             :;           ;
              ;            ;;          :
              |            ;;          |
              :           : ;          ;
               ;          : ;         :
               :          ; :         |
                ;         ; :         ;
                :         ; :        :
                 ;        ; :        |
                 :        ; :        ;
                  ;       : :       :
                  : ;   : :  ;  ;   |
                   ;:   ; ;  :  :   :
                   : \    ;   \      "-.
                   :      ;    \        \
                   ;      :     \      .d$b
                  db.___.d$b     \__.g$$$$$b
                  $$$$$$$$$$     :$$$$$$$$$$b
                  $$$$$$$$$$      T$$$$$$$$$$;
                  :$$$$$$$$$       T$$$$$$$$$$
                   $$$$$$$$$        `T$$$$$$$$b
                   $$$$$$$$;          T$$$$$$$$;
                   :$$$$$$$            T$$$$$$$$
                   :$$$$$$$             T$$$$$$$;
                    $$$$$$$              T$$$$$$$
                    $$$$$$$               T$$$$$$;
                    $$$$$$$                T$$$$$$
                    :$$$$$;                 T$$$$$b
                    :$$$$$;                  T$$$S$b.
                    :$$$$S;                   SSS$$$$bp.
                    :$$$$S;                   :S$$$$$S$$;
                    $S$$SS;                    S$$$$$$SP
                   :$SSSSS;                    :$$$$$$S
                   $$$$$$$;                     $$$$$$$
                   $$$$$$$$                     :$$SS$$
                   $$$$$$$$                      SSS$$$
                   $$$$$$$$                      :$$$$;
                   :$$$$SS;                       `^^'
                    TSSSSP
                     `^^'
*/


 //GETTERS AND SETTERS
    bool getManzanita(){
            return isManzanita;
        }
    void setManzanita(bool manzanita){
            this->isManzanita = manzanita;
        }

    void setUp(Rectangle* pUp){
        this->up=pUp;
    }
    void setDown(Rectangle* down){
        this->down=down;
    }
    void setRight(Rectangle* right){
        this->right=right;
    }

    void setLeft(Rectangle* left){
        this->left=left;
    }

    Rectangle *getUp()
    {
        return up;
    }

    Rectangle *getDown()
    {
        return down;
    }

    Rectangle *getLeft()
    {
        return left;
    }

    Rectangle *getRight()
    {
        return right;
    }

    int getPosX()
    {
        return posX;
    }

    void setPosX(int value)
    {
        posX = value;
    }

    int getPosY()
    {
        return posY;
    }

    void setPosY(int value)
    {
        posY = value;
    }
    void setIsFinal(bool valor){
        this->isFinal=valor;
    }

    bool getIsFinal(){
        return isFinal;
    }

};

#endif // RECTANGLE_H
