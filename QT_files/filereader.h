#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <uzytkownik.h>
#include <QFile>
#include <QString>
#include <QList>
#include <iostream>
class FileReader
{
public:
    FileReader(): if_error(false){}
    virtual ~FileReader()
    {
        lista_uzytkownikow.clear();
    }
    virtual QList<Uzytkownik> open_read_close_log_in(QString)=0;
    virtual int open_read_close_rejestracion(QString, QString, QString, QString)=0;
    bool if_error;
    std::string ID;
protected:
    Uzytkownik uzytkownik;
    QList<Uzytkownik> lista_uzytkownikow;
};

#endif // FILEREADER_H
