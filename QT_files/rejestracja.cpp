#include "rejestracja.h"
#include "ui_rejestracja.h"
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>

Rejestracja::Rejestracja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rejestracja)
{
    ui->setupUi(this);
}

Rejestracja::~Rejestracja()
{
    delete ui;
}

void Rejestracja::on_pushButton_OK_clicked()
{
    QString login = ui->lineEdit_Login->text();
    QString haslo = ui->lineEdit_Haslo->text();
    QString email = ui->lineEdit_Email->text();
    emit Rejestracja_OK_SIGNAL(login, haslo, email);
    this->close();
}

void Rejestracja::on_pushButton_Cancel_clicked()
{
    this->close();
}


