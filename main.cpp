#include "compliermainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ComplierMainWidget w;
    w.show();

    return a.exec();
}
