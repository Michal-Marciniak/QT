#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QStatusBar>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setFixedSize(500, 400);
    ui->setupUi(this);
    QPixmap zdjecie("/home/michal/Documents/QT_Repozytorium/PROG_2_TEST/zdjecie_blogu.JPG");
    zdjecie.scaled(this->size());
    ui->label_zdjecie_blogu->setPixmap(zdjecie.scaled(200,400,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// ***************** REJESTRACJA *************************

void MainWindow::Rejestracja_SLOT(QString login, QString haslo, QString email) {

    QString type = ui->lineEdit_file_type->text();
    if(type!="csv" && type!="txt" && type!="html") {
        QMessageBox::warning(this, "Status Rejestracji", "nieznany typ pliku");
    }
    else {

    std::vector <FileReader *> readers;
    readers.emplace_back(new FileReader_txt());
    readers.emplace_back(new FileReader_csv());
    readers.emplace_back(new Filereader_html());
    unsigned int i=0;
    int result=0;
    for (auto x: readers)
    {
        if(x->ID==type.toStdString()) break;
        i++;
    }
    result=readers.at(i)->open_read_close_rejestracion(login, haslo, email, type);
    if(result == 0)
    {
        QMessageBox::information(this, "Status Rejestracji", "Poprawna rejestracja");
    }
    else if(result == 1)
    {
        QMessageBox::warning(this, "Error", "Błąd otwarcia pliku");
    }
    else if(result == 2) {
        QMessageBox::warning(this, "Status Rejestracji", "Podano błedny adres eamil");
    }
    for (auto x: readers) delete x;
    }

}


void MainWindow::on_pushButton_Zarejestruj_sie_clicked()
{
    rejestracja = new Rejestracja(this);
    rejestracja->show();
    connect(rejestracja, SIGNAL(Rejestracja_OK_SIGNAL(QString,QString,QString)),this, SLOT(Rejestracja_SLOT(QString,QString,QString)));
}



// ***************** LOGOWANIE *************************

void MainWindow::Logowanie_SLOT(QString login, QString password)
{
    uzytkownik_mainwidow.login_= login;
    uzytkownik_mainwidow.haslo_= password;
    QString type = ui->lineEdit_file_type->text();
    if(type != "csv" && type != "txt" && type != "html") {
        QMessageBox::warning(this, "Status Rejestracji", "nieznany typ pliku");
    }
    else {
    std::vector <FileReader *> readers;
    readers.emplace_back(new FileReader_txt());
    readers.emplace_back(new FileReader_csv());
    readers.emplace_back(new Filereader_html());
    unsigned int i=0;
    for (auto x: readers)
    {
        if(x->ID==type.toStdString()) break;
        i++;
    }

    lista_uzytkownikow=readers.at(i)->open_read_close_log_in("Dane_uzytkownikow."+type);
    if(readers.front()->if_error==true) QMessageBox::information(this, "Logowanie", "Błąd otwarcia pliku");
    else{


    int temp=0;
    for (auto x: lista_uzytkownikow) {
    if((x.login_ == uzytkownik_mainwidow.login_) && (x.haslo_ == uzytkownik_mainwidow.haslo_)) {
        QMessageBox::information(this, "Logowanie", "Poprawne zalogowanie");
        uzytkownik_mainwidow.zalogowany=true;
        temp=1;
        }
    }
    if (temp==0)
    {
        QMessageBox::warning(this, "Logowanie", "Wpisano błędne login lub hasło");
    }
    }

    for (auto x: readers) delete x;
    }
}
void MainWindow::on_pushButton_Zaloguj_sie_clicked()
{
    logowanie = new Logowanie(this);
    logowanie->show();
    connect(logowanie , SIGNAL(Logowanie_OK_SIGNAL(QString,QString)),this, SLOT(Logowanie_SLOT(QString,QString)));
 // "D:/Foldery/Studia/2 SEM/PROE/ZadProg2/App
}




// ***************** POSTY *************************

void MainWindow::on_pushButton_Dodaj_wyswietl_post_clicked()
{
    if(uzytkownik_mainwidow.zalogowany){
    posty_uzytkownikow = new Posty(this);
    posty_uzytkownikow->uzytkownik_posty=uzytkownik_mainwidow;
    posty_uzytkownikow->show();
    } else {
        QMessageBox::warning(this, "Post", "Możesz dodać post jeśli jesteś zalogowany");
    }
}

// ***************** INNE *************************

void MainWindow::on_pushButton_Wyloguj_sie_clicked()
{
   if(uzytkownik_mainwidow.zalogowany==true)
   {
   uzytkownik_mainwidow.zalogowany = false;
   ui->statusBar->showMessage("Poprawne wylogowanie", 1500);
   }
   else
   {
        ui->statusBar->showMessage("Nie jestes zalogowany", 1500);
   }
}

void MainWindow::on_pushButton_Zamknij_program_clicked()
{

    close();
}

void MainWindow::on_actionPomoc_triggered()
{
    QMessageBox::information(this,"Twórcy blogu","Made by Michał Marciniak and Tomasz Żydowicz");
}


