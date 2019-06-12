#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QPen>




class Rectangle:public QGraphicsRectItem
{//Herencia de la clase QGraphicsRectItem

public:     //atributos de la clase
    int num;
    Rectangle *up;
    Rectangle *down;
    Rectangle *left;
    Rectangle *right;
    int posX=0;
    int posY=0;


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

    }


    Rectangle(int posX,int posY,int num){//Este constructor inicializa los atributos y establece el tamanio del rectangulo
        this->posX=posX;
        this->posY=posY;
        setRect(posX,posY,20,20);
        //setFlag(QGraphicsItem::ItemIsFocusable);
        this->up=NULL;
        this->down=NULL;
        this->right=NULL;
        this->left=NULL;
        this->num=num;
    }

    Rectangle(int posX,int posY,Rectangle* actual){//Este constructor inicializa los atributos y establece el tamanio del rectangulo
        this->posX=posX;
        this->posY=posY;
        setRect(posX,posY,20,20);
        //setFlag(QGraphicsItem::ItemIsFocusable);
        this->up=NULL;
        this->down=NULL;
        this->right=NULL;
        this->left=NULL;
    }

    void setKeys(Rectangle *nActual){
        setUp(nActual->getUp());
        setDown(nActual->getDown());
        setLeft(nActual->getLeft());
        setRight(nActual->getRight());

    }


/*
    void keyPressEvent(QKeyEvent *event)//metodo para el manejo con los botones
    {
        if(event->key() == Qt::Key_Left){
            if(actual->getLeft()!=NULL){
                setPos(x()-20,y());
                actual=actual->getLeft();
                setFocus();


            }
        }
        else if(event->key() == Qt:: Key_Right){
            if(actual->getRight()!=NULL){

                //setKeys(getRight());

                setPos(x()+20,y());
                actual=actual->getRight();
                setFocus();


            }

        }
        else if (event->key() == Qt:: Key_Down) {
            if(actual->getDown()!=NULL){
                //setKeys(getDown());
                setPos(x(),y()+20);
                actual=actual->getDown();
                setFocus();



            }


        }

        else if (event->key() == Qt:: Key_Up) {
            if(getUp()!=NULL){

                //setKeys(getUp());
                setPos(x(),y()-20);
                actual=actual->getUp();
                setFocus();

            }


        }



    }
*/




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

};

#endif // RECTANGLE_H
