#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ventana = new menuPrincipal();
    //conexion
    QObject::connect(ventana,SIGNAL(back()) , this,SLOT(esconder()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::esconder(){

    this->setVisible(true);
    ventana->setVisible(false);

}


void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("G7v3R2001");
    db.setDatabaseName("cashflow_db");

    if(db.open()){

        QMessageBox::information(this, "Connection", "Database Connected Successfully");

    } else{
        QSqlError error = db.lastError();
                QMessageBox::information(this, "Connection", error.databaseText());

    }
}

void MainWindow::on_Ingresar_clicked()
{

    QString nombreValido = "Gerardo";
    short int contrasenaValida = 1234;
    bool bandera1 = false;
    bool bandera2 = false;
    QString userName=ui->inputUsername->text();
    QString password=ui->inputPassword->text();
    int password2 = password.toInt();

    if(userName == nombreValido){
        bandera1 = true;
    }
    if (password2 == contrasenaValida){
        bandera2 = true;
    }

    if (bandera1 and bandera2 == true){
        ui->alertaLogin->setText("lOGRADO");
        this->setVisible(false);
        ventana->setVisible(true);
    }

}
