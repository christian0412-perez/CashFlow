#include "menuprincipal.h"
#include "ui_menuprincipal.h"

menuPrincipal::menuPrincipal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuPrincipal)
{
    ui->setupUi(this);
    ventana2 = new indicadoresDeDinero();
    //conexion
    QObject::connect(ventana2,SIGNAL(back()) , this,SLOT(esconder()));
}

menuPrincipal::~menuPrincipal()
{
    delete ui;
}

void menuPrincipal::esconder(){

    this->setVisible(true);
    ventana2->setVisible(false);

}

void menuPrincipal::on_pushButton_clicked()
{
    emit(back());
}

void menuPrincipal::on_buttonIndicadores_clicked()
{
    this->setVisible(false);
    ventana2->setVisible(true);
}
