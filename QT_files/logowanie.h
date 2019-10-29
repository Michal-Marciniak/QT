#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QDialog>
#include "uzytkownik.h"

namespace Ui {
class Logowanie;
}

class Logowanie : public QDialog
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = 0);
    ~Logowanie();

public slots:
    void on_pushButton_OK_clicked();
    void on_pushButton_Cancel_clicked();
signals:
    void Logowanie_OK_SIGNAL(QString, QString);

public:
    Ui::Logowanie *ui;

public:
    QString path_log;
};

#endif // LOGOWANIE_H
