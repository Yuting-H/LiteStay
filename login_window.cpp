#include "login_window.h"
#include "ui_login_window.h"

/*!
 * \brief displays the login window
 *
 */
login_window::login_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_window)
{
    ui->setupUi(this);
}

login_window::~login_window()
{
    delete ui;
}
