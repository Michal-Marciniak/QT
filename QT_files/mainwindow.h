#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QDebug>
#include <QList>
#include "logowanie.h"
#include "posty.h"
#include "rejestracja.h"
#include "uzytkownik.h"
#include "filereader_txt.h"
#include "filereader_csv.h"
#include "filereader_html.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_Zaloguj_sie_clicked();

    void on_pushButton_Dodaj_wyswietl_post_clicked();

    void on_pushButton_Wyloguj_sie_clicked();

    void on_pushButton_Zamknij_program_clicked();

    void on_pushButton_Zarejestruj_sie_clicked();

    void on_actionPomoc_triggered();



    void Logowanie_SLOT(QString, QString);

    void Rejestracja_SLOT(QString, QString, QString);

private:
    Ui::MainWindow *ui;
    Logowanie *logowanie;
    Posty *posty_uzytkownikow;
    Rejestracja *rejestracja;
    Uzytkownik uzytkownik_mainwidow;
    QList<Uzytkownik> lista_uzytkownikow;
    friend class Logowanie;
    friend class Rejestracja;
};

#endif // MAINWINDOW_H
