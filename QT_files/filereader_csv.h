#ifndef FILEREADER_CSV_H
#define FILEREADER_CSV_H
#include "filereader.h"

class FileReader_csv: public FileReader
{
public:
    FileReader_csv();
    ~FileReader_csv(){lista_uzytkownikow.clear();}
    QList<Uzytkownik> open_read_close_log_in(QString) override;
    int open_read_close_rejestracion(QString, QString, QString, QString) override;

};

#endif // FILEREADER_CSV_H
