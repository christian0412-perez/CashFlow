#ifndef INDICADORESDEDINERO_H
#define INDICADORESDEDINERO_H

#include <QDialog>

namespace Ui {
class indicadoresDeDinero;
}

class indicadoresDeDinero : public QDialog
{
    Q_OBJECT

public:
    explicit indicadoresDeDinero(QWidget *parent = nullptr);
    ~indicadoresDeDinero();

signals:
    void back();

private slots:

    void on_button_GeratePDF_2_clicked();

    void on_button_GeratePDF_clicked();



private:
    Ui::indicadoresDeDinero *ui;
};

#endif // INDICADORESDEDINERO_H
