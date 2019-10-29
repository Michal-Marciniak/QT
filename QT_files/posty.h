#ifndef POSTY_H
#define POSTY_H

#include <QDialog>
#include<uzytkownik.h>

namespace Ui {
class Posty;
}

class Posty : public QDialog
{
    Q_OBJECT

public:
    QString pathlog;
    explicit Posty(QWidget *parent = nullptr);
    Uzytkownik uzytkownik_posty;
    ~Posty();

private slots:
    void on_pushButton_Dodaj_clicked();

    void on_pushButton_wczytaj_posty_clicked();

private:
    Ui::Posty *ui;


};

#endif // POSTY_H
