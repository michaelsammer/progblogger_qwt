#include "customqwt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomQWT w;
    w.show();

    return a.exec();
}
