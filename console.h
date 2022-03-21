#ifndef CONSOLE_H
#define CONSOLE_H

#include <QMainWindow>
#include "watchEditor.h"

namespace Ui {
class console;
}

class console : public QMainWindow
{
    Q_OBJECT

public:
    explicit console(QWidget *parent = 0);
    ~console();
    QSerialPort * serial;
    QByteArray getBuf();
    Ui::console *ui;
private:
    QByteArray buf;
    QTimer *timer;

public slots:
    void update();
private slots:
    void on_pushButton_clicked();
};

#endif // CONSOLE_H
