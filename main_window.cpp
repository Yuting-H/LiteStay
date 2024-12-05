#include "main_window.h"
#include "qsqlquery.h"
#include "ui_main_window.h"
#include "query.h"
#include <QDebug>

/*!
 * \brief displays the main window, most user interactions occur through this
 */
main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::main_window)
{
    ui->setupUi(this);
    setFixedSize(1024, 578);
    setWindowTitle("Hotel Management System");
    q = new query();
}

main_window::~main_window()
{

    delete ui;
}

//Enables buttons that let the user change employee and room info
void main_window::elevate_privilege() {
    ui->staff_btn->setEnabled(true);
    ui->room_btn->setEnabled(true);
}

//switches pages when user clicks
void main_window::on_booking_btn_clicked()
{
    ui->query_window->setCurrentIndex(0);
}

void main_window::on_add_booking_btn_clicked()
{
    ui->query_window->setCurrentIndex(1);
}


void main_window::on_room_btn_clicked()
{
    ui->query_window->setCurrentIndex(2);
}

void main_window::on_staff_btn_clicked()
{
    ui->query_window->setCurrentIndex(3);
}


void main_window::on_add_staff_record_btn_clicked()
{
    //get values from UI fields
    QString id = ui->staff_id_input->text();
    QString username = ui->staff_username_input->text();
    QString password = ui->staff_password_input->text();
    QString priv = ui->staff_privilege_input->currentText();

    //write to db
    q->reset_sql_command();
    q->add_staff(id, username, password, priv);
    on_search_staff_record_btn_clicked();
}

void main_window::on_search_staff_record_btn_clicked()
{
    //create result object
    q->reset_sql_command();
    QSqlQuery result = q->read_staff();

    //keep track of row
    int row_num = 0;

    //display data on UI
    while (result.next()) {
        ui->staff_table->setRowCount(row_num + 1);
        qDebug() << result.value("id") << result.value("username").toString();

        ui->staff_table->setItem(row_num, 0, new QTableWidgetItem(result.value("id").toString()));
        ui->staff_table->setItem(row_num, 1, new QTableWidgetItem(result.value("username").toString()));
        ui->staff_table->setItem(row_num, 2, new QTableWidgetItem(result.value("password").toString()));
        ui->staff_table->setItem(row_num, 3, new QTableWidgetItem(result.value("privilege").toString()));
        row_num++;
    }

}

