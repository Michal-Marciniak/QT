#include "filereader_csv.h"
#include <QTextStream>

FileReader_csv::FileReader_csv()
{
    lista_uzytkownikow.clear();
    ID="csv";
}

QList<Uzytkownik> FileReader_csv::open_read_close_log_in(QString file_name)
{
    QFile file("/home/michal/Documents/QT_Repozytorium/PROG_2_TEST/"+file_name);

    if(!file.open(QIODevice::ReadOnly)){
       if_error=true;
       return lista_uzytkownikow;
    }
    QTextStream in(&file);

    while(!in.atEnd()){
    in >> uzytkownik.login_ >> uzytkownik.haslo_ >> uzytkownik.email_ ;
    lista_uzytkownikow.push_back(uzytkownik) ;
    }

    file.close();
    return lista_uzytkownikow;

}

int FileReader_csv::open_read_close_rejestracion(QString login,QString password,QString email, QString type)
{

    QFile file("/home/michal/Documents/QT_Repozytorium/PROG_2_TEST/Dane_uzytkownikow"+type);
    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
        return 1;
    }
    QTextStream out(&file);

    QString key = "@gmail.com";
    if (email.right(10) == key) {
    out << login << " " << password << " " << email << "\n";
    file.flush();
    file.close();
    return 0;
    }
    else {
        file.flush();
        file.close();
        return 2;
    }

}


