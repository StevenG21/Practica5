#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

enum Direcciones{up,down,left,right,none};
class player : public QGraphicsItem,public QObject
{

public:
    explicit player(QObject *parent = nullptr);
    QPixmap *bomber;
    void set_pos(int,int);
    int get_posx(){
        return posx;
    }
    int get_posy(){
        return posy;
    }

    QRectF CDI();
    QRectF CAA();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void set_dir(Direcciones dir){
        this->dir=dir;

    }
private:
    int posx;
    int posy;
    int velx , vely;
    float imx,imy,ancho,alto;
    Direcciones dir;
    Direcciones last;

public slots:
    void frame();

};

#endif // PLAYER_H
