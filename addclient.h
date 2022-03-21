#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class addClient;
}

class addClient : public QDialog
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = nullptr);
    ~addClient();
    QSqlDatabase db;
    Ui::addClient *clientIHM;
private:

};

#endif // ADDCLIENT_H
