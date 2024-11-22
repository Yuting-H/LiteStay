#include "login_window.h"
#include "ui_login_window.h"
#include "query.h"

/*!
 * \brief displays the login window
 *
 */

//query
login_window::login_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login_window)
{
    ui->setupUi(this);
    setWindowTitle("Login To Hotel");
    q = new query();
}

login_window::~login_window()
{
    delete ui;
}

void login_window::received_login_request() {
    this->close();
}

/*!
 * \brief when login button clicked, check creditials, if exists user emit login signal
 */
void login_window::on_login_button_clicked()
{
    QString username = ui->username_input->text();
    QString password = ui->password_input->text();

    //validate login info
    if (q->valid_login_info(username, password)) {
        emit login_window::login_request();

        //check if user has admin privilege
        if(q->user_is_admin(username)) {
            emit login_window::elevate_privilege();
            qDebug() << "Logged in with elevated privilege";
        }
    }else {
        ui->error_lbl->setText("Username/Password not found");
    }


}

