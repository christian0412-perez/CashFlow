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
    db.setPassword("");
    db.setDatabaseName("C:/Users/lacac/Desktop/db/mydb");

    if(db.open()){

        QMessageBox::information(this, "Connection", "Database Connected Successfully");

    } else{
        QSqlError error = db.lastError();
                QMessageBox::information(this, "Connection", error.databaseText());

    }
}

void MainWindow::on_Ingresar_clicked()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE" , "MyConnect");
        db.setHostName("127.0.0.1");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("C:/Users/lacac/Desktop/db/mydb");

        QString userName=ui->inputUsername->text();
        QString password=ui->inputPassword->text();
        if(db.open()){

            QMessageBox::information(this, "Connection", "Database Connected Successfully");

        } else{
            QSqlError error = db.lastError();
                    QMessageBox::information(this, "Connection", error.databaseText());

        }

        if(!db.isOpen()){
        qDebug()<<"Fallo al abrir";
        return;
        }
       else{

        QSqlQuery qry;
        if(qry.exec("select * from users where username='"+userName+"'and password= '"+password+"'")){
            int count=0;
            while(qry.next()){
                count++;
            }
            if(count==1){
                ui->alertaLogin->setText("logrado");
            }
        }
        }
}
