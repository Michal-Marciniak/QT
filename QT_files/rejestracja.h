#ifndef REJESTRACJA_H
#define REJESTRACJA_H

#include <QDialog>
#include "uzytkownik.h"

namespace Ui {
class Rejestracja;
}

class Rejestracja : public QDialog
{
    Q_OBJECT

public:
    explicit Rejestracja(QWidget *parent = 0);
    ~Rejestracja();

private slots:
    void on_pushButton_Cancel_clicked();
    void on_pushButton_OK_clicked();

signals:
    void Rejestracja_OK_SIGNAL(QString, QString, QString);

private:
    Ui::Rejestracja *ui;
    Uzytkownik uzytkownik;
};

#endif // REJESTRACJA_H
