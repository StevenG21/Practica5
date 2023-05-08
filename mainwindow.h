#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <ctime>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "player.h"
#include <QTimer>
#include "mapa.h"
#include <QGraphicsRectItem>
#define filas 17
#define columnas 17
#define ancho 63
#define alto 53
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent *event);


private slots:
    void hmov();


private:
    int matriz[filas][columnas];
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsScene* mapa();
    QGraphicsView* view;

    player *jugador;
   // mapa *m1;
    int vel;
    int vel_auto;
    QTimer *timer;
    QGraphicsRectItem *rect;
};
#endif // MAINWINDOW_H
