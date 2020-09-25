#ifndef PITANJE_H
#define PITANJE_H

#include "QSqlQuery"
#include <QDialog>
#include <QComboBox>
#include <QRadioButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QCheckBox>

namespace Ui {
class Pitanje;
}

class Pitanje : public QDialog
{
    Q_OBJECT

public:
    explicit Pitanje(QWidget *parent = nullptr, QString br = "");
    ~Pitanje();

signals:
    void odg(bool maybe,QString broj);

private slots:
    void odgovoreno_radioButton();
    void odgovoreno_comboBox();
    void odgovoreno_pushBtn_true();
    void odgovoreno_pushBtn_false();
    void odgovoreno_checkBox();

private:

    Ui::Pitanje *ui;

    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;

    QPushButton *button;

    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;

    QRadioButton *radiobutton_1;
    QRadioButton *radiobutton_2;
    QRadioButton *radiobutton_3;
    QRadioButton *radiobutton_4;
    QRadioButton *radiobutton_5;

    QCheckBox *check1;
    QCheckBox *check2;
    QCheckBox *check3;
    QCheckBox *check4;
    QCheckBox *check5;


    bool tacnoodg = true;
    QString redni = 0;
    int count[3]={0,0,0};

    QComboBox *comboBox;
};

#endif // PITANJE_H
