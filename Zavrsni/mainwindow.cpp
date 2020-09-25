#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pitanje.h"
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //podesavanje visine i sirine
    this->setFixedHeight(600);
    this->setFixedWidth(800);

    //podesavanje progressBara
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(50);


    //disableovanje buttona
    ui->pushButton_1->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);
    ui->pushButton_13->setDisabled(true);
    ui->pushButton_14->setDisabled(true);
    ui->pushButton_15->setDisabled(true);
    ui->pushButton_16->setDisabled(true);
    ui->pushButton_17->setDisabled(true);
    ui->pushButton_18->setDisabled(true);
    ui->pushButton_19->setDisabled(true);
    ui->pushButton_20->setDisabled(true);
    ui->pushButton_21->setDisabled(true);
    ui->pushButton_22->setDisabled(true);
    ui->pushButton_23->setDisabled(true);
    ui->pushButton_24->setDisabled(true);
    ui->pushButton_25->setDisabled(true);

    //stilizovanje buttona
    ui->pushButton_1->setStyleSheet("background-color:blue");
    ui->pushButton_2->setStyleSheet("background-color:red");
    ui->pushButton_3->setStyleSheet("background-color:yellow");
    ui->pushButton_4->setStyleSheet("background-color:green");
    ui->pushButton_5->setStyleSheet("background-color:blue");
    ui->pushButton_6->setStyleSheet("background-color:purple");
    ui->pushButton_7->setStyleSheet("background-color:red");
    ui->pushButton_8->setStyleSheet("background-color:green");
    ui->pushButton_9->setStyleSheet("background-color:blue");
    ui->pushButton_10->setStyleSheet("background-color:red");
    ui->pushButton_11->setStyleSheet("background-color:green");
    ui->pushButton_12->setStyleSheet("background-color:yellow");
    ui->pushButton_13->setStyleSheet("background-color:blue");
    ui->pushButton_14->setStyleSheet("background-color:red");
    ui->pushButton_15->setStyleSheet("background-color:purple");
    ui->pushButton_16->setStyleSheet("background-color:yellow");
    ui->pushButton_17->setStyleSheet("background-color:green");
    ui->pushButton_18->setStyleSheet("background-color:blue");
    ui->pushButton_19->setStyleSheet("background-color:red");
    ui->pushButton_20->setStyleSheet("background-color:purple");
    ui->pushButton_21->setStyleSheet("background-color:purple");
    ui->pushButton_22->setStyleSheet("background-color:purple");
    ui->pushButton_23->setStyleSheet("background-color:yellow");
    ui->pushButton_24->setStyleSheet("background-color:green");
    ui->pushButton_25->setStyleSheet("background-color:yellow");

    //otvaranje baze podataka kviz
    sql=QSqlDatabase::addDatabase("QSQLITE");
    sql.setDatabaseName("C:/Users/ammar/Desktop/WORKSPACE/SQLite/kviz.db");
    if(sql.open())
        ui->statusbar->showMessage("Database open and ready to use.");
    else
        ui->statusbar->showMessage("Database could not be open.");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loggedIn(QString ime, QString prezime)
{
    //kupljenje informacija vezano za bodove i ime korisnika
    naziv=ime;
    currentScore=0;
    //updateovanje status bara
    ui->statusbar->showMessage(ime+" "+prezime);
    ui->progressBar->setValue(0);
    //enableovanje buttona
    ui->pushButton_1->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_8->setEnabled(true);
    ui->pushButton_9->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    ui->pushButton_11->setEnabled(true);
    ui->pushButton_12->setEnabled(true);
    ui->pushButton_13->setEnabled(true);
    ui->pushButton_14->setEnabled(true);
    ui->pushButton_15->setEnabled(true);
    ui->pushButton_16->setEnabled(true);
    ui->pushButton_17->setEnabled(true);
    ui->pushButton_18->setEnabled(true);
    ui->pushButton_19->setEnabled(true);
    ui->pushButton_20->setEnabled(true);
    ui->pushButton_21->setEnabled(true);
    ui->pushButton_22->setEnabled(true);
    ui->pushButton_23->setEnabled(true);
    ui->pushButton_24->setEnabled(true);
    ui->pushButton_25->setEnabled(true);

}

void MainWindow::odgovoreno(bool maybe,QString br)
{
    //poslje odgovora na pitanje button se ponovo disablea
    if(br=="1"){
        ui->pushButton_1->setEnabled(false);
    } else if(br=="2"){
        ui->pushButton_2->setEnabled(false);
    } else if(br=="3"){
        ui->pushButton_3->setEnabled(false);
    } else if(br=="4"){
        ui->pushButton_4->setEnabled(false);
    } else if(br=="5"){
        ui->pushButton_5->setEnabled(false);
    } else if(br=="6"){
        ui->pushButton_6->setEnabled(false);
    } else if(br=="7"){
        ui->pushButton_7->setEnabled(false);
    } else if(br=="8"){
        ui->pushButton_8->setEnabled(false);
    } else if(br=="9"){
        ui->pushButton_9->setEnabled(false);
    } else if(br=="10"){
        ui->pushButton_10->setEnabled(false);
    } else if(br=="11"){
        ui->pushButton_11->setEnabled(false);
    } else if(br=="12"){
        ui->pushButton_12->setEnabled(false);
    } else if(br=="13"){
        ui->pushButton_13->setEnabled(false);
    } else if(br=="14"){
        ui->pushButton_14->setEnabled(false);
    } else if(br=="15"){
        ui->pushButton_15->setEnabled(false);
    } else if(br=="16"){
        ui->pushButton_16->setEnabled(false);
    } else if(br=="17"){
        ui->pushButton_17->setEnabled(false);
    } else if(br=="18"){
        ui->pushButton_18->setEnabled(false);
    } else if(br=="19"){
        ui->pushButton_19->setEnabled(false);
    } else if(br=="20"){
        ui->pushButton_20->setEnabled(false);
    } else if(br=="21"){
        ui->pushButton_21->setEnabled(false);
    } else if(br=="22"){
        ui->pushButton_22->setEnabled(false);
    } else if(br=="23"){
        ui->pushButton_23->setEnabled(false);
    } else if(br=="24"){
        ui->pushButton_24->setEnabled(false);
    } else if(br=="25"){
        ui->pushButton_25->setEnabled(false);
    }
    //ako je pitanje tacno odgovoreno povecaj skor
    if(maybe){
        currentScore++;
        ui->progressBar->setValue(currentScore);
    }

    //provjeravanje da li je odgovoreno na sva pitanja
    if(!ui->pushButton_1->isEnabled()){
        if(!ui->pushButton_2->isEnabled()){
            if(!ui->pushButton_3->isEnabled()){
                if(!ui->pushButton_4->isEnabled()){
                    if(!ui->pushButton_5->isEnabled()){
                        if(!ui->pushButton_6->isEnabled()){
                            if(!ui->pushButton_7->isEnabled()){
                                if(!ui->pushButton_8->isEnabled()){
                                    if(!ui->pushButton_9->isEnabled()){
                                        if(!ui->pushButton_10->isEnabled()){
                                            if(!ui->pushButton_11->isEnabled()){
                                                if(!ui->pushButton_12->isEnabled()){
                                                    if(!ui->pushButton_13->isEnabled()){
                                                        if(!ui->pushButton_14->isEnabled()){
                                                            if(!ui->pushButton_15->isEnabled()){
                                                                if(!ui->pushButton_16->isEnabled()){
                                                                    if(!ui->pushButton_17->isEnabled()){
                                                                        if(!ui->pushButton_18->isEnabled()){
                                                                            if(!ui->pushButton_19->isEnabled()){
                                                                                if(!ui->pushButton_20->isEnabled()){
                                                                                    if(!ui->pushButton_21->isEnabled()){
                                                                                        if(!ui->pushButton_22->isEnabled()){
                                                                                            if(!ui->pushButton_23->isEnabled()){
                                                                                                if(!ui->pushButton_24->isEnabled()){
                                                                                                    if(!ui->pushButton_25->isEnabled()){
                                                                                                        finito();
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

void MainWindow::finito()
{
    QSqlQuery query;
    //updateovanje bodova
    query.prepare("update studenti set Bodovi ="+QString::number(currentScore*2)+" where Ime = '"+naziv+"'");
    query.exec();
    //updateovanje datuma
    query.prepare("update studenti set Datum ='"+QDateTime::currentDateTime().toString()+"' where Ime = '"+naziv+"'");
    query.exec();

}




void MainWindow::on_actionLog_In_triggered()
{
    log=new LoginWindow(this);
    connect(log,SIGNAL(loginSuccessful(QString,QString)),this,SLOT(loggedIn(QString,QString)));
    log->exec();
}
void MainWindow::on_actionPregled_triggered()
{
    pregled = new Pregled(this);
    pregled->exec();
}


void MainWindow::on_pushButton_1_pressed()
{
    pitanje=new Pitanje(this,"1");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_2_pressed()
{
    pitanje=new Pitanje(this,"2");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_3_pressed()
{
    pitanje=new Pitanje(this,"3");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_4_pressed()
{
    pitanje=new Pitanje(this,"4");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_5_pressed()
{
    pitanje=new Pitanje(this,"5");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_6_pressed()
{
    pitanje=new Pitanje(this,"6");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_7_pressed()
{
    pitanje=new Pitanje(this,"7");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_8_pressed()
{
    pitanje=new Pitanje(this,"8");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_9_pressed()
{
    pitanje=new Pitanje(this,"9");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_10_pressed()
{
    pitanje=new Pitanje(this,"10");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_11_pressed()
{
    pitanje=new Pitanje(this,"11");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_12_pressed()
{
    pitanje=new Pitanje(this,"12");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_13_pressed()
{
    pitanje=new Pitanje(this,"13");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_14_pressed()
{
    pitanje=new Pitanje(this,"14");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_15_pressed()
{
    pitanje=new Pitanje(this,"15");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_16_pressed()
{
    pitanje=new Pitanje(this,"16");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_17_pressed()
{
    pitanje=new Pitanje(this,"17");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_18_pressed()
{
    pitanje=new Pitanje(this,"18");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_19_pressed()
{
    pitanje=new Pitanje(this,"19");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_20_pressed()
{
    pitanje=new Pitanje(this,"20");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_21_pressed()
{
    pitanje=new Pitanje(this,"21");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_22_pressed()
{
    pitanje=new Pitanje(this,"22");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_23_pressed()
{
    pitanje=new Pitanje(this,"23");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_24_pressed()
{
    pitanje=new Pitanje(this,"24");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}

void MainWindow::on_pushButton_25_pressed()
{
    pitanje=new Pitanje(this,"25");
    connect(pitanje,SIGNAL(odg(bool,QString)),this,SLOT(odgovoreno(bool,QString)));
    pitanje->exec();
}


