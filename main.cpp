#include "watchEditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    watchEditor w;
    w.show();
    return a.exec();
}
