#include "logowanie.h"
#include "ui_logowanie.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Logowanie::Logowanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logowanie)
{
    ui->setupUi(this);
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::on_pushButton_OK_clicked()
{
    QString login =ui->lineEdit_Login->text();
    QString haslo =ui->lineEdit_Haslo->text();
    emit Logowanie_OK_SIGNAL(login, haslo);
    this->close();
}

void Logowanie::on_pushButton_Cancel_clicked()
{
    this->close();
}
