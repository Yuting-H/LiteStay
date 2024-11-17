#include "window_manager.h"
#include <QDebug>
#include <QDir>
#include <QApplication>

/*!
 * \brief the main function
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    //creates QApp
    QApplication a(argc, argv);

    //creates window
    window_manager w;

    return a.exec();
}
