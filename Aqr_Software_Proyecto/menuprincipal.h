#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QDialog>
#include "indicadoresdedinero.h"

namespace Ui {
class menuPrincipal;
}

class menuPrincipal : public QDialog
{
    Q_OBJECT

public:
    explicit menuPrincipal(QWidget *parent = nullptr);
    ~menuPrincipal();

signals:
    void back();

private slots:
    void on_pushButton_clicked();
    void esconder();

    void on_buttonIndicadores_clicked();

private:
    Ui::menuPrincipal *ui;
    indicadoresDeDinero  *ventana2;
};

#endif // MENUPRINCIPAL_H
