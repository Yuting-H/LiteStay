#include "window_manager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    window_manager w;

    return a.exec();
}
