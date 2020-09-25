#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "QSqlQuery"
#include <QtSql>
#include <QMessageBox>


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void loginSuccessful(QString,QString);

private slots:
    void on_pushButton_pressed();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
