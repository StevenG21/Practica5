#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QGraphicsView* vista = new QGraphicsView(this);
       QGraphicsScene* escena = mapa();

       // Asigna la escena a la vista

       vista->setScene(escena);
       vista->setSceneRect(0,0,ancho*columnas,alto*filas);
       setCentralWidget(vista);

       // Agrega la vista a la ventana principal
jugador = new player;




escena->addItem(jugador);
jugador->setPos(50,50);
   // scene->setSceneRect(0,0,945,745);




//m1 = new mapa();


   // scene->addItem(jugador->solido());
    vel=5;
    vel_auto=1;



    timer =  new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(jugador->frame()));
    timer->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()== Qt::Key_F4) close();

    if(event->key()== Qt::Key_A ){
        jugador->set_dir(Direcciones::left);

    }

    if(event->key()== Qt::Key_S ){
        jugador->set_dir(Direcciones::down);

    }

    if(event->key()== Qt::Key_D){
        jugador->set_dir(Direcciones::right);

    }

    if(event->key()== Qt::Key_W ){
        jugador->set_dir(Direcciones::up);

    }

    if(event->key()== Qt::Key_M){
        if(timer->isActive()) timer->stop();
        else timer->start(500);

    }
jugador->setPos(jugador->get_posx(),jugador->get_posy());
jugador->frame();

}

QGraphicsScene *MainWindow::mapa()
{
    int X=(-ancho/2);
    int Y=(-alto/2);
    srand(time(NULL));
    QGraphicsScene* map = new QGraphicsScene();
   // map->setSceneRect(0, 0, ancho * columnas, alto * filas);
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(i==0 || j==0 || i==filas-1 || j==columnas-1){
                matriz[i][j]=1;
                cout << matriz[i][j] <<" ";
            }
            else if(i%2 == 0 && j%2==0){
                matriz[i][j]=1;
                cout << matriz[i][j] <<" ";
            }
            else if((i==1 && (j==1||j==2))||(j==1 && i==2)||(i==filas-2 && (j==columnas-3 || j==columnas-2)) || (i==filas-3 && j== columnas-2)){
                matriz[i][j]=0;
                cout << matriz[i][j] <<" ";//Inicio del jugador
            }
            else{
                matriz[i][j]=rand()%2+2;
                cout << matriz[i][j] <<" ";//aleatorio entre destruibles y libres 2;3
            }
        }
        cout <<endl;
    }



    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
             X = i * ancho;
             Y = j * alto;
                  if(matriz[i][j]==0){
                // Crear objeto QGraphicsPixmapItem para el bloque 0
                        QGraphicsPixmapItem* bloque0 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSuelo.png"));
                        bloque0->setPos(X, Y);

                        map->addItem(bloque0);
               }
                  if(matriz[i][j]==1){
                      // Crear objeto QGraphicsPixmapItem para el bloque 1
                              QGraphicsPixmapItem* bloque1 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSolido.png"));
                              bloque1->setPos(X, Y);
                               bloque1->setData(Qt::UserRole, 1); // Establecer el atributo data en 1
                              map->addItem(bloque1);
               }
                  if(matriz[i][j]==2){
                      // Crear objeto QGraphicsPixmapItem para el bloque 2
                             QGraphicsPixmapItem* bloque2 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpDestruible.png"));
                             bloque2->setPos(X, Y);
                             bloque2->setData(Qt::UserRole, 2); // Establecer el atributo data en 2

                             map->addItem(bloque2);

               }
                  if(matriz[i][j]==3){
                      // Crear objeto QGraphicsPixmapItem para el bloque 3
                             QGraphicsPixmapItem* bloque3 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSuelo.png"));
                             bloque3->setPos(X, Y);
                             map->addItem(bloque3);
               }




                //agregar más casos para cada imagen que necesites
            }

        }
    map->setSceneRect(map->itemsBoundingRect());
    return map;
}





void MainWindow::hmov()
{

}
