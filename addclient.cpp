#include "addclient.h"
#include "ui_addclient.h"

addClient::addClient(QWidget *parent) :
    QDialog(parent),
    clientIHM(new Ui::addClient)
{
    clientIHM->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("172.20.10.3");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("dbClient.clients");
        db.setPort(8889);
}

addClient::~addClient()
{
    delete clientIHM;
}
