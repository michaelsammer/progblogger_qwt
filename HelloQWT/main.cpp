#include "helloqwt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloQWT w;
    w.show();

    return a.exec();
}
