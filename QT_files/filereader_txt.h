#ifndef FILEREADER_TXT_H
#define FILEREADER_TXT_H
#include "filereader.h"


class FileReader_txt: public FileReader
{
public:
    FileReader_txt();
    ~FileReader_txt(){lista_uzytkownikow.clear();}
    QList<Uzytkownik> open_read_close_log_in(QString) override;
    int open_read_close_rejestracion(QString,QString,QString, QString) override;

};

#endif // FILEREADER_TXT_H
