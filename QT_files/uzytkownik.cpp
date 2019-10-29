#include "uzytkownik.h"
Uzytkownik& Uzytkownik::operator=(const Uzytkownik &copy)
{
    if(this!=&copy)
    {
        login_=copy.login_;
        haslo_=copy.haslo_;
        email_=copy.email_;
    }
    return *this;
}
Uzytkownik::Uzytkownik()
{
    login_="0";
    haslo_="0";
    email_="0";
}
Uzytkownik::~Uzytkownik()
{

}
