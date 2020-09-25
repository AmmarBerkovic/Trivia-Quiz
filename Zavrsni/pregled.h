#ifndef PREGLED_H
#define PREGLED_H

#include <QDialog>
#include "QSqlQuery"
#include <QSqlQueryModel>

namespace Ui {
class Pregled;
}

class Pregled : public QDialog
{
    Q_OBJECT

public:
    explicit Pregled(QWidget *parent = nullptr);
    ~Pregled();

private:
    Ui::Pregled *ui;
    QSqlQueryModel *model;
};

#endif // PREGLED_H
