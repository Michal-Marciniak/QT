#include "posty.h"
#include "ui_posty.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Posty::Posty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Posty)
{
    ui->setupUi(this);

}

Posty::~Posty()
{
    delete ui;
}

void Posty::on_pushButton_Dodaj_clicked()
{
   // /home/michal/Documents/QT_Repozytorium/proe_2019l_g103_mm_tz_sysytem_blogowy_beta/QT/pliki_QT

    QFile file("D:/Foldery/Studia/2 SEM/PROE/ZadProg2/App/posty_uzytkownikow.txt");

    if(!file.open(QFile::WriteOnly | QFile::Text | QFile::Append)){
        QMessageBox::warning(this, "Error", "Błąd otwarcia pliku");
    }
    QTextStream out(&file);
    
    QString post_uzytkownika = ui->plainTextEdit_Post_uzytkownika->toPlainText();
    out << post_uzytkownika <<"\t" << "autor: " << uzytkownik_posty.login_<<  "\n";
    QMessageBox::information(this, "Post", "Post został dodany");
    file.flush();
    file.close();
}

void Posty::on_pushButton_wczytaj_posty_clicked()
{
    QFile file("D:/Foldery/Studia/2 SEM/PROE/ZadProg2/App/posty_uzytkownikow.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Błąd otwarcia pliku");
    }
    QTextStream in(&file);
    QString post_uzytkownika = in.readAll();
    ui->plainTextEdit_Post_uzytkownika->setPlainText(post_uzytkownika);
    file.close();
}
