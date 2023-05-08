#include "player.h"
#define vel 4
#include <iostream>
using namespace std;
player::player(QObject *parent) : QObject(parent)
{
    dir=Direcciones::none;
    last=Direcciones::down;
    ancho=630/7; //tamaño del sprite
    alto=360/4;
    velx=vely=imy=imx=0;

    bomber = new QPixmap(":/Images/NeoEarlyBomberman3.gif");
}

void player::set_pos(int xn, int yn)
{
    posx=xn;
    posy=yn;
}

QRectF player::CDI()
{
    return QRectF(posx+velx,posy,(63),(53));
}

QRectF player::CAA()
{
    return QRectF(posx,posy+vely,63-4,53-15);
}





void player::frame()
{

    switch (dir) {
    case up:
        imy=0;
        velx =  0;
        vely = -vel;
        break;
    case down:
        imy=90*2;
        velx = 0;
        vely = vel;
        break;
    case Direcciones::left:
        imy=90*3;
        velx = -vel;
        vely = 0;
        break;
    case Direcciones::right:
        imy=90;
        velx = vel;
        vely = 0;
        break;
    case none:
    velx=vely=0;
        imy=90*2;
        break;

    }
    imx +=90;
    if(imx >=90*7){
        imx=0;
    }
//    QList<QGraphicsItem*> items = collidingItems(Qt::IntersectsItemBoundingRect);
//        for (QGraphicsItem* item : qAsConst(items)) {
//            if (item->data(Qt::UserRole) == 1 || item->data(Qt::UserRole) == 2) {
//                // Si el objeto colisionado es un bloque 1 o 2, detén al jugador
//                switch (dir) {
//                case up:
//                    imy=0;
//                    velx =  0;
//                    vely = vel;
//                    break;
//                case down:
//                    imy=90*2;
//                    velx = 0;
//                    vely = -vel;
//                    break;
//                case left:
//                    imy=90*3;
//                    velx = vel;
//                    vely = 0;
//                    break;
//                case right:
//                    imy=90;
//                    velx = -vel;
//                    vely = 0;
//                    break;
//                case none:
//                velx=vely=0;
//                    imy=90*2;
//                    break;

//                }

//            }
//        }


    this->update();
    posx += velx;
    posy +=vely;
    cout<<posx<<" x "<<posy<<" y "<<endl;
}
QRectF player::boundingRect() const
{

    return QRectF(posx,posy,ancho,alto);
}

void player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(CDI());
    painter->drawRect(CAA());
    painter->drawPixmap(posx,posy,*bomber,imx,imy,ancho,alto);

}
