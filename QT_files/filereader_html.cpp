#include "filereader_html.h"
#include <QTextStream>
#include <QMessageBox>

Filereader_html::Filereader_html()
{
    lista_uzytkownikow.clear();
    ID = "html";
}
Filereader_html::~Filereader_html()
{
    lista_uzytkownikow.clear();
}

QList<Uzytkownik> Filereader_html::open_read_close_log_in(QString file_name)
{
    QFile file("/home/michal/Documents/QT_Repozytorium/PROG_2_TEST/"+file_name);

    if(!file.open(QFile::ReadOnly)){
        if_error=true;
        return lista_uzytkownikow;
    }
    QTextStream in(&file);

    QString poczatek_pliku_html;
    QString koniec_pliku_html;
    in >> poczatek_pliku_html;

    if(poczatek_pliku_html != "<html>"){
        file.close();
        return lista_uzytkownikow;
    }

    while(!in.atEnd()){
    in >> uzytkownik.login_ >> uzytkownik.haslo_ >> uzytkownik.email_ ;
    lista_uzytkownikow.push_back(uzytkownik) ;
        in >> koniec_pliku_html;
        if(koniec_pliku_html != "</html>") {
            uzytkownik.login_ = koniec_pliku_html;
            in >> uzytkownik.haslo_ >> uzytkownik.email_ ;
            lista_uzytkownikow.push_back(uzytkownik);
        } else {
            return lista_uzytkownikow;
            file.close();
        }
    }

    file.close();
}

int Filereader_html::open_read_close_rejestracion(QString login, QString password, QString email, QString type)
{
    QFile file("/home/michal/Documents/QT_Repozytorium/PROG_2_TEST/Dane_uzytkownikow."+type);
    if(!file.open(QFile::ReadWrite | QFile::Text | QFile::Append)){
        return 1;
    }
    QTextStream in_out(&file);

    QString poczatek_pliku_html;
    in_out >> poczatek_pliku_html;

    if(poczatek_pliku_html != "<html>") {
        file.close();
    }

    QString key = "@gmail.com";
    if (email.right(10) == key) {
               in_out << "\n";
               in_out << login << " " << password << " " << email << "<br>";
               file.flush();
               file.close();
               return 0;

        } else {

        file.flush();
        file.close();
        return 2;
    }
}
