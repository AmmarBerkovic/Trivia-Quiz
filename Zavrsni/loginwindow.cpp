#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
//pogledaj dali se stavljaju navodnici ili <>
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_pressed()
{
    QString ime=ui->ime->text();
    QString sifra=ui->sifra->text();
    //provjera
    QSqlQuery query;
    bool maybe=false;
    if(query.exec("SELECT * FROM studenti")){
        while(query.next()){
            if(ime == query.value("Korisnicko Ime").toString() && sifra == query.value("Sifra").toString()){
                //Disable off buttone, status kod ispisuje ime i prezime
                maybe=true;
                emit loginSuccessful(query.value("Ime").toString(),query.value("Prezime").toString());
            }
        }
        //QMessageBox feedback
        if(maybe){
            QMessageBox::information(this,"Success","Uspijesno odradjena radnja!");
            this->hide();
        } else {
            QMessageBox::information(this,"Not found","Radnja nije uspijela!");
        }
    }

}
