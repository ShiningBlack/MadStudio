#include "studiomainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MadStudioMainWindow w;
    w.show();
    return a.exec();
}
