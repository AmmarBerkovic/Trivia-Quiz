#include "pregled.h"
#include "ui_pregled.h"

Pregled::Pregled(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pregled)
{
    ui->setupUi(this);
    QSqlQuery query;
    //pokretanje querya
    query.exec("select Ime,Prezime,Bodovi,Datum from studenti");
    //inicijaliziranje modela i dodavanje ga na table view
    model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tableView->setModel(model);

}

Pregled::~Pregled()
{
    delete ui;
}
