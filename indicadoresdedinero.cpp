#include "indicadoresdedinero.h"
#include "ui_indicadoresdedinero.h"
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QApplication>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>

indicadoresDeDinero::indicadoresDeDinero(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::indicadoresDeDinero)
{
    ui->setupUi(this);

}



indicadoresDeDinero::~indicadoresDeDinero()
{
    delete ui;
}

void indicadoresDeDinero::on_button_GeratePDF_2_clicked()
{
    emit(back());
}

void indicadoresDeDinero::on_button_GeratePDF_clicked()
{
    QPdfWriter pdf ("/Users/mario/Downloads/Quinto cuatrimestre/miPrimerPDF.pdf");

    QPainter painter(&pdf);

    painter.setPen(Qt::black);
    painter.drawText(2500,200,"Semana");
    painter.drawText(3500,200,"Semana");
    painter.drawText(4500,200,"Semana");
    painter.drawText(5500,200,"Semana");
    painter.drawText(6500,200,"Semana");
    painter.drawText(7500,200,"Final");
    painter.setPen(Qt::blue);
    painter.drawText(300,200,"Cuentas Por Cobrar");
    //Lineas horizontales
    painter.drawLine(300,300,8000,300);
    painter.drawLine(300,500,8000,500);
    painter.drawLine(300,700,8000,700);
    painter.drawLine(300,900,8000,900);
    painter.drawLine(300,1100,8000,1100);
    painter.drawLine(300,1300,8000,1300);
    painter.drawLine(300,1500,8000,1500);
    painter.drawLine(300,1700,8000,1700);
    painter.drawLine(300,1900,8000,1900);
    //Lineas verticales
    painter.drawLine(2400,100,2400,1900);
    painter.drawLine(3400,100,3400,1900);
    painter.drawLine(4400,100,4400,1900);
    painter.drawLine(5400,100,5400,1900);
    painter.drawLine(6400,100,6400,1900);
    painter.drawLine(7400,100,7400,1900);
    painter.drawLine(8000,100,8000,1900);
    painter.setPen(Qt::black);
    painter.drawText(300,400,"Uno");
    painter.drawText(300,600,"Dos");
    painter.drawText(300,800,"Tres");
    painter.drawText(300,1000,"Cuatro");
    painter.drawText(300,1200,"Cinco");
    painter.drawText(300,1400,"Seis");
    painter.drawText(300,1600,"Siete");
    painter.drawText(300,1800,"Ocho");
    painter.drawText(300,2000,"Total Cuentas por Cobrar");

    painter.end();
}
//Dos $ 157.90 $ 157.90 $ 157.90 $ 157.90 $ - $ -
//Tres $ 1,360.90 $ 1,360.90 $ 1,360.90 $ 1,360.90 $ -
//Cuatro $ 850.00 $ 850.00 $ 850.00 $ 850.00 $ -
//Cinco $ 2,091.00 $ 2,091.00 $ 2,091.00 $ 2,091.00 $ -
//Seis $ 2,250.00 $ 2,250.00 $ 2,250.00 $ 2,250.00 $ 2,250.00 $ 2,250.00
//Siete $ 328.00 $ 328.00 $ 328.00 $ 328.00 $ -
//Ocho $ 8,637.00 $ 8,637.00 $ 8,637.00 $ 8,637.00 $ 8,637.00 $ 8,637.00
//Total Cuentas por Cobrar $ 20,924.80 $ 20,924.80 $ 20,924.80 $ 20,924.80 $ 16,137.00 $ 16,137.00");
