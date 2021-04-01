#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,90);
    trem2 = new Trem(2,460,30);
    trem3 = new Trem(3,870,90);
    trem4 = new Trem(4,330,280);
    trem5 = new Trem(5,600,280);


    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_pushButton_clicked()
{
    if(trem1->getVelocidade()<200)
        trem1->start();
    if(trem2->getVelocidade()<200)
        trem2->start();
    if(trem3->getVelocidade()<200)
        trem3->start();
    if(trem4->getVelocidade()<200)
        trem4->start();
    if(trem5->getVelocidade()<200)
        trem5->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_pushButton_2_clicked()
{
    if(trem1->isRunning())
        trem1->terminate();
    if(trem2->isRunning())
        trem2->terminate();
    if(trem3->isRunning())
        trem3->terminate();
    if(trem4->isRunning())
        trem4->terminate();
    if(trem5->isRunning())
        trem5->terminate();
}

void MainWindow::on_controle_t1_valueChanged(int value)
{
    trem1->setVelocidade(value);
}

void MainWindow::on_controle_t2_valueChanged(int value)
{
    trem2->setVelocidade(value);
}

void MainWindow::on_controle_t3_valueChanged(int value)
{
    trem3->setVelocidade(value);
}

void MainWindow::on_controle_t4_valueChanged(int value)
{
    trem4->setVelocidade(value);
}

void MainWindow::on_controle_t5_valueChanged(int value)
{
    trem5->setVelocidade(value);
}
