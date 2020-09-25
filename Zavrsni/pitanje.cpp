#include "pitanje.h"
#include "ui_pitanje.h"
#include <mainwindow.h>
#include <QDebug>
Pitanje::Pitanje(QWidget *parent, QString a) :
    QDialog(parent),
    ui(new Ui::Pitanje)
{
    ui->setupUi(this);

    QString odg1,odg2,odg3,odg4,odg5;
    tacnoodg=true;
    redni=a;

    //postavljanje pitanja
    QSqlQuery query;
    if(query.exec("select * from pitanja where redniBroj = "+a)){

        while(query.next()){
            ui->pitanje->setText(query.value("pitanje").toString());
            odg1=query.value("odg1").toString();
            odg2=query.value("odg2").toString();
            odg3=query.value("odg3").toString();
            odg4=query.value("odg4").toString();
            odg5=query.value("odg5").toString();
        }


        //utvrdjivanje tacnih odgovora
        if(odg1[odg1.length()-1] == '!'){
            if(count[0]==0){
                count[0]=1;
            } else if(count[1]==0){
                count[1]=1;
            } else if(count[2]==0){
                count[2]=1;
            }
        }
        if(odg2[odg2.length()-1] == '!'){
            if(count[0]==0){
                count[0]=2;
            } else if(count[1]==0){
                count[1]=2;
            } else if(count[2]==0){
                count[2]=2;
            }
        }
        if(odg3[odg3.length()-1] == '!'){
            if(count[0]==0){
                count[0]=3;
            } else if(count[1]==0){
                count[1]=3;
            } else if(count[2]==0){
                count[2]=3;
            }
        }
        if(odg4[odg4.length()-1] == '!'){
            if(count[0]==0){
                count[0]=4;
            } else if(count[1]==0){
                count[1]=4;
            } else if(count[2]==0){
                count[2]=4;
            }
        }
        if(odg5[odg5.length()-1] == '!'){
            if(count[0]==0){
                count[0]=5;
            } else if(count[1]==0){
                count[1]=5;
            } else if(count[2]==0){
                count[2]=5;
            }
        }
    }
    //skidanje ! sa tacnih odg4
    if(odg1[odg1.length()-1] == '!'){
        odg1=odg1.left(odg1.length()-1);
    }
    if(odg2[odg2.length()-1] == '!'){
        odg2=odg2.left(odg2.length()-1);
    }
    if(odg3[odg3.length()-1] == '!'){
        odg3=odg3.left(odg3.length()-1);
    }
    if(odg4[odg4.length()-1] == '!'){
        odg4=odg4.left(odg4.length()-1);
    }
    if(odg5[odg5.length()-1] == '!'){
        odg5=odg5.left(odg5.length()-1);
    }


    //postavljanje odgovora
    if(a=="1" || a=="5" || a=="9" || a=="13" || a=="18"){
        radiobutton_1 = new QRadioButton(this);
        radiobutton_1->setText(odg1);
        radiobutton_2 = new QRadioButton(this);
        radiobutton_2->setText(odg2);
        radiobutton_3 = new QRadioButton(this);
        radiobutton_3->setText(odg3);
        radiobutton_4 = new QRadioButton(this);
        radiobutton_4->setText(odg4);
        radiobutton_5 = new QRadioButton(this);
        radiobutton_5->setText(odg5);

        button=new QPushButton(this);
        button->setText("Odgovori");

        connect(button,SIGNAL(pressed()),SLOT(odgovoreno_radioButton()));

        verticalLayout = new QVBoxLayout(this);
        verticalLayout->addWidget(radiobutton_1);
        verticalLayout->addWidget(radiobutton_2);
        verticalLayout->addWidget(radiobutton_3);
        verticalLayout->addWidget(radiobutton_4);
        verticalLayout->addWidget(radiobutton_5);
        verticalLayout->addWidget(button);

        groupBox=new QGroupBox(this);
        groupBox->setStyleSheet("QGroupBox{margin-top: 50px}");
        groupBox->setLayout(verticalLayout);


    } else if (a=="2" || a=="7" || a=="10" || a=="14" || a=="19"){
        comboBox = new QComboBox(this);
        comboBox->addItem(odg1);
        comboBox->addItem(odg2);
        comboBox->addItem(odg3);
        comboBox->addItem(odg4);
        comboBox->addItem(odg5);

        button=new QPushButton(this);
        button->setText("Odgovori");

        connect(button,SIGNAL(pressed()),SLOT(odgovoreno_comboBox()));

        verticalLayout = new QVBoxLayout(this);
        verticalLayout->addWidget(comboBox);
        verticalLayout->addWidget(button);

        groupBox=new QGroupBox(this);
        groupBox->setStyleSheet("QGroupBox{margin-top: 50px}");
        groupBox->setLayout(verticalLayout);

    } else if (a=="4" || a=="8" || a=="11" || a=="17" || a=="24"){
        btn1 = new QPushButton(this);
        btn1->setText(odg1);
        if(count[0]==1){
            connect(btn1,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_true()));
        } else {
            connect(btn1,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_false()));
        }

        btn2 = new QPushButton(this);
        btn2->setText(odg2);
        if(count[0]==2){
            connect(btn2,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_true()));
        } else {
            connect(btn2,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_false()));
        }

        btn3 = new QPushButton(this);
        btn3->setText(odg3);
        if(count[0]==3){
            connect(btn3,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_true()));
        } else {
            connect(btn3,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_false()));
        }

        btn4 = new QPushButton(this);
        btn4->setText(odg4);
        if(count[0]==4){
            connect(btn4,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_true()));
        } else {
            connect(btn4,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_false()));
        }

        btn5 = new QPushButton(this);
        btn5->setText(odg5);
        if(count[0]==5){
            connect(btn5,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_true()));
        } else {
            connect(btn5,SIGNAL(pressed()),SLOT(odgovoreno_pushBtn_false()));
        }

        verticalLayout = new QVBoxLayout(this);
        verticalLayout->addWidget(btn1);
        verticalLayout->addWidget(btn2);
        verticalLayout->addWidget(btn3);
        verticalLayout->addWidget(btn4);
        verticalLayout->addWidget(btn5);

        groupBox=new QGroupBox(this);
        groupBox->setStyleSheet("QGroupBox{margin-top: 50px}");
        groupBox->setLayout(verticalLayout);


    } else if (a=="6" || a=="15" || a=="20" || a=="21" || a=="22" || a=="3" || a=="12" || a=="16" || a=="23" || a=="25"){
        check1 = new QCheckBox(this);
        check1->setText(odg1);
        check2 = new QCheckBox(this);
        check2->setText(odg2);
        check3 = new QCheckBox(this);
        check3->setText(odg3);
        check4 = new QCheckBox(this);
        check4->setText(odg4);
        check5 = new QCheckBox(this);
        check5->setText(odg5);

        button=new QPushButton(this);
        button->setText("Odgovori");
        connect(button,SIGNAL(pressed()),SLOT(odgovoreno_checkBox()));

        verticalLayout = new QVBoxLayout(this);
        verticalLayout->addWidget(check1);
        verticalLayout->addWidget(check2);
        verticalLayout->addWidget(check3);
        verticalLayout->addWidget(check4);
        verticalLayout->addWidget(check5);
        verticalLayout->addWidget(button);

        groupBox=new QGroupBox(this);
        groupBox->setStyleSheet("QGroupBox{margin-top: 50px}");
        groupBox->setLayout(verticalLayout);

    }


}

Pitanje::~Pitanje()
{
    delete ui;
}

void Pitanje::odgovoreno_radioButton()
{
    if(radiobutton_1->isChecked()){
        if(count[0]!=1 && count[1]!=1 && count[2]!=1){
            tacnoodg=false;
        }
    }
    if(radiobutton_2->isChecked()){
        if(count[0]!=2 && count[1]!=2 && count[2]!=2){
            tacnoodg=false;
        }
    }
    if(radiobutton_3->isChecked()){
        if(count[0]!=3 && count[1]!=3 && count[2]!=3){
            tacnoodg=false;
        }
    }
    if(radiobutton_4->isChecked()){
        if(count[0]!=4 && count[1]!=4 && count[2]!=4){
            tacnoodg=false;
        }
    }
    if(radiobutton_5->isChecked()){
        if(count[0]!=5 && count[1]!=5 && count[2]!=5){
            tacnoodg=false;
        }
    }
    if(!radiobutton_1->isChecked() && !radiobutton_2->isChecked() && !radiobutton_3->isChecked() && !radiobutton_4->isChecked() && !radiobutton_5->isChecked()){
        tacnoodg=false;
    }
    this->hide();
    emit odg(tacnoodg,redni);

}

void Pitanje::odgovoreno_comboBox()
{
    if(comboBox->currentIndex()+1 != count[0]){
        tacnoodg = false;
    }
    this->hide();
    emit odg(tacnoodg,redni);
}

void Pitanje::odgovoreno_pushBtn_true()
{
    tacnoodg=true;
    this->hide();
    emit odg(tacnoodg,redni);
}

void Pitanje::odgovoreno_pushBtn_false()
{
    tacnoodg=false;
    this->hide();
    emit odg(tacnoodg,redni);

}

void Pitanje::odgovoreno_checkBox()
{
    //ako checkani nema medju tacnima, baci false
    if(check1->isChecked()){
        if(count[0]!=1 && count[1]!=1 && count[2]!=1){
            tacnoodg=false;
        }
    }
    if(check2->isChecked()){
        if(count[0]!=2 && count[1]!=2 && count[2]!=2){
            tacnoodg=false;
        }
    }
    if(check3->isChecked()){
        if(count[0]!=3 && count[1]!=3 && count[2]!=3){
            tacnoodg=false;
        }
    }
    if(check4->isChecked()){
        if(count[0]!=4 && count[1]!=4 && count[2]!=4){
            tacnoodg=false;
        }
    }
    if(check5->isChecked()){
        if(count[0]!=5 && count[1]!=5 && count[2]!=5){
            tacnoodg=false;
        }
    }
    //svi iz counta moraju bit tacni
    if(count[0]==1 || count[1]==1 || count[2]==1){
        if(!check1->isChecked()){
            tacnoodg=false;
        }
    }
    if(count[0]==2 || count[1]==2 || count[2]==2){
        if(!check2->isChecked()){
            tacnoodg=false;
        }
    }
    if(count[0]==3 || count[1]==3 || count[2]==3){
        if(!check3->isChecked()){
            tacnoodg=false;
        }
    }
    if(count[0]==4 || count[1]==4 || count[2]==4){
        if(!check4->isChecked()){
            tacnoodg=false;
        }
    }
    if(count[0]==5 || count[1]==5 || count[2]==5){
        if(!check5->isChecked()){
            tacnoodg=false;
        }
    }

    this->hide();
    emit odg(tacnoodg,redni);
}
