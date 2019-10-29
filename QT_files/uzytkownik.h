#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <QString>

class Uzytkownik {
public:
    Uzytkownik();
    ~Uzytkownik();
    Uzytkownik& operator=(const Uzytkownik&);
    QString login_;
    QString haslo_;
    QString email_;

    bool zalogowany = false;
};

#endif // UZYTKOWNIK_H
