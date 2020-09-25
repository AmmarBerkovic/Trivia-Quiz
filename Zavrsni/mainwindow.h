#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QMainWindow>
#include "loginwindow.h"
#include "pitanje.h"
#include "pregled.h"
#include "QSqlQuery"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loggedIn(QString ime,QString prezime);
    void odgovoreno(bool maybe,QString broj);

private slots:
    void on_actionLog_In_triggered();
    void finito();


    void on_pushButton_11_pressed();

    void on_pushButton_2_pressed();

    void on_pushButton_1_pressed();

    void on_pushButton_3_pressed();

    void on_pushButton_4_pressed();

    void on_pushButton_5_pressed();

    void on_pushButton_6_pressed();

    void on_pushButton_7_pressed();

    void on_pushButton_8_pressed();

    void on_pushButton_9_pressed();

    void on_pushButton_10_pressed();

    void on_pushButton_12_pressed();

    void on_pushButton_13_pressed();

    void on_pushButton_14_pressed();

    void on_pushButton_15_pressed();

    void on_pushButton_16_pressed();

    void on_pushButton_17_pressed();

    void on_pushButton_18_pressed();

    void on_pushButton_19_pressed();

    void on_pushButton_20_pressed();

    void on_pushButton_21_pressed();

    void on_pushButton_22_pressed();

    void on_pushButton_23_pressed();

    void on_pushButton_24_pressed();

    void on_pushButton_25_pressed();

    void on_actionPregled_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase sql;
    LoginWindow *log;
    Pitanje *pitanje;
    Pregled *pregled;

    int currentScore=0;
    QString naziv="";

};
#endif // MAINWINDOW_H
