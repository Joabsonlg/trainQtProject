#include "trem.h"
#include <QtCore>

QMutex areaCritica1;
QMutex areaCritica2;
QMutex areaCritica3;
QMutex areaCritica4;
QMutex areaCritica5;
QMutex areaCritica6;
QMutex areaCritica7;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função que altera a velocidade
void Trem::setVelocidade(int x) {
    this->velocidade = x + 2*(100-x);
}

//Função que retorna o valor da velocidade
int Trem::getVelocidade() {
    return this->velocidade;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (velocidade != 200) {
            switch(ID){
            case 1:     //Trem 1
                if (y == 30 && x == 310) areaCritica1.lock();
                else if (y == 150 && x == 310) areaCritica1.unlock();

                if (y == 130 && x == 330) areaCritica3.lock();
                else if (y == 150 && x == 170) areaCritica3.unlock();

                if (y == 30 && x < 330)
                    x+=10;
                else if (x == 330 && y < 150)
                    y+=10;
                else if (x > 60 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2: //Trem 2
                if (y == 30 && x == 580) areaCritica2.lock();
                else if (y == 150 && x == 580) areaCritica2.unlock();

                if (y == 130 && x == 600) areaCritica5.lock();
                else if (y == 150 && x == 460) areaCritica5.unlock();

                if (y == 150 && x == 480) areaCritica4.lock();
                else if (y == 130 && x == 330) areaCritica4.unlock();

                if (y == 150 && x == 350) areaCritica1.lock();
                else if (y == 30 && x == 350) areaCritica1.unlock();

                if (y == 30 && x <600)
                    x+=10;
                else if (x == 600 && y < 150)
                    y+=10;
                else if (x > 330 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 3: //Trem 3
                if (y == 150 && x == 750) areaCritica6.lock();
                else if (y == 130 && x == 600) areaCritica6.unlock();

                if (y == 150 && x == 620) areaCritica2.lock();
                else if (y == 30 && x == 620) areaCritica2.unlock();

                if (y == 30 && x <870)
                    x+=10;
                else if (x == 870 && y < 150)
                    y+=10;
                else if (x > 600 && y == 150)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 4: //Trem 4
                if (y == 170 && x == 190) areaCritica3.lock();
                else if (y == 150 && x == 350) areaCritica3.unlock();

                if (y == 150 && x == 310) areaCritica4.lock();
                else if (y == 170 && x == 460) areaCritica4.unlock();

                if (y == 150 && x == 440) areaCritica7.lock();
                else if (y == 280 && x == 440) areaCritica7.unlock();

                if (y == 150 && x <460)
                    x+=10;
                else if (x == 460 && y < 280)
                    y+=10;
                else if (x > 190 && y == 280)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 5: //Trem 5
                if (y == 280 && x == 480) areaCritica7.lock();
                else if (y == 150 && x == 480) areaCritica7.unlock();

                if (y == 170 && x == 460) areaCritica5.lock();
                else if (y == 150 && x == 620) areaCritica5.unlock();

                if (y == 150 && x == 580) areaCritica6.lock();
                else if (y == 170 && x == 730) areaCritica6.unlock();

                if (y == 150 && x <730)
                    x+=10;
                else if (x == 730 && y < 280)
                    y+=10;
                else if (x > 460 && y == 280)
                    x-=10;
                else
                    y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            default:
                break;
            }
            msleep(velocidade);
        }
    }
}




