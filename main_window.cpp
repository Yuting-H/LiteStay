#include "main_window.h"
#include "qsqlquery.h"
#include "ui_main_window.h"
#include "staff_query.h"
#include "room_query.h"
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
    sq = new staff_query();
    rq = new room_query();
    bq = new booking_query();

    //remove default record numbering
    ui->staff_table->verticalHeader()->setVisible(false);
    ui->room_table->verticalHeader()->setVisible(false);
    ui->booking_table->verticalHeader()->setVisible(false);
    ui->add_booking_avaliable_rooms->verticalHeader()->setVisible(false);
    ui->add_booking_summary_table->verticalHeader()->setVisible(false);


    //initialize table items
    on_search_room_btn_clicked();
    on_search_staff_record_btn_clicked();
    on_booking_find_booking_btn_clicked();
    on_add_booking_find_room_btn_clicked();
    update_add_room_summary_table();
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

void main_window::received_login_request()
{
    this->show();
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
    sq->reset_sql_command();
    sq->add_staff(id, username, password, priv);
    on_search_staff_record_btn_clicked();
}

void main_window::on_search_staff_record_btn_clicked()
{
    //create result object
    sq->reset_sql_command();
    QSqlQuery result = sq->read_staff();

    //keep track of row
    int row_num = 0;

    //reset table view
    ui->staff_table->setRowCount(0);

    //display data on UI
    while (result.next()) {
        QString id;

        ui->staff_table->setRowCount(row_num + 1);
        ui->staff_table->setItem(row_num, 0, new QTableWidgetItem(QString::number(row_num)));
        ui->staff_table->setItem(row_num, 1, new QTableWidgetItem(id = result.value("id").toString()));
        ui->staff_table->setItem(row_num, 2, new QTableWidgetItem(result.value("username").toString()));
        ui->staff_table->setItem(row_num, 3, new QTableWidgetItem(result.value("password").toString()));
        ui->staff_table->setItem(row_num, 4, new QTableWidgetItem(result.value("privilege").toString()));

        //create delete button
        QPushButton* button = new QPushButton(QString("Delete"));
        ui->staff_table->setCellWidget(row_num, 5, button);

        //connect delete button to function
        QObject::connect(button, &QPushButton::clicked, [ id, this]() {
            sq->delete_staff(id);
            this->on_search_staff_record_btn_clicked();
        });

        row_num++;
    }

}

void main_window::on_search_room_btn_clicked()
{
    rq->reset_sql_command();
    QSqlQuery result = rq->read_room();

    int row_num = 0;

    //reset table view
    ui->room_table->setRowCount(0);

    while(result.next()) {
        QString roomid;

        ui->room_table->setRowCount(row_num + 1);
        ui->room_table->setItem(row_num, 0, new QTableWidgetItem(QString::number(row_num)));
        ui->room_table->setItem(row_num, 1, new QTableWidgetItem(roomid = result.value("roomid").toString()));
        ui->room_table->setItem(row_num, 2, new QTableWidgetItem(result.value("roomtype").toString()));

        QPushButton* button = new QPushButton(QString("Delete"));
        ui->room_table->setCellWidget(row_num, 3, button);

        QObject::connect(button, &QPushButton::clicked, [ roomid, this]() {
            rq->delete_room(roomid);
            this->on_search_room_btn_clicked();
        });

        row_num++;
    }
}


/*!
 * \brief main_window::on_add_room_btn_clicked
 */
void main_window::on_add_room_btn_clicked()
{
    QString roomid = ui->room_num_input_2->text();
    QString room_type = ui->room_type_input->text();

    rq->reset_sql_command();
    rq->add_room(roomid, room_type);
    on_search_room_btn_clicked();
    on_add_booking_find_room_btn_clicked(); //also update avaliable rooms
}

/*!
 * \brief Display avaliable rooms
 */
void main_window::on_add_booking_find_room_btn_clicked()
{
    QString startdate = ui->add_booking_start_date_input->text();
    QString enddate = ui->add_booking_end_date_input->text();

    //result stores avaliale room info
    QSqlQuery result = bq->find_avaliable_room(startdate, enddate);

    int row_num = 0;

    ui->add_booking_avaliable_rooms->setRowCount(0);

    while (result.next()) {
        QString bookid;

        //display data
        ui->add_booking_avaliable_rooms->setRowCount(row_num + 1);
        ui->add_booking_avaliable_rooms->setItem(row_num, 1, new QTableWidgetItem(bookid = result.value("roomid").toString()));
        ui->add_booking_avaliable_rooms->setItem(row_num, 2, new QTableWidgetItem(result.value("roomtype").toString())); //room type

        //button to select a room
        QPushButton* button = new QPushButton(QString("Select room"));
        ui->add_booking_avaliable_rooms->setCellWidget(row_num, 0, button);

        QObject::connect(button, &QPushButton::clicked, [ bookid, this]() {

            ui->add_booking_room_num_input->setText(bookid);
        });

        row_num++;
    }
}


void main_window::on_add_booking_clicked()
{
    QString booked = "false";
    QString roomid = ui->add_booking_room_num_input->text();
    QString guestfirstname = ui->add_booking_firstname_input->text();
    QString guestlastname = ui->add_booking_lastname_input->text();
    QString startdate = ui->add_booking_start_date_input->text();
    QString enddate = ui->add_booking_end_date_input->text();

    bq->add_booking(booked, roomid, guestfirstname, guestlastname, startdate, enddate);

    on_add_booking_find_room_btn_clicked();
    update_add_room_summary_table();

}


//search botton on booking page
void main_window::on_booking_find_booking_btn_clicked()
{
    bq->reset_sql_command();
    QSqlQuery result = bq->read_booking();

    int row_num = 0;

    ui->booking_table->setRowCount(0);

    while (result.next()) {
        QString bookid;

        ui->booking_table->setRowCount(row_num + 1);
        ui->booking_table->setItem(row_num, 0, new QTableWidgetItem(bookid = result.value("bookid").toString()));
        ui->booking_table->setItem(row_num, 1, new QTableWidgetItem(result.value("ischeckedin").toString()));
        ui->booking_table->setItem(row_num, 2, new QTableWidgetItem(result.value("roomid").toString()));
        ui->booking_table->setItem(row_num, 3, new QTableWidgetItem(result.value("guestfirstname").toString()));
        ui->booking_table->setItem(row_num, 4, new QTableWidgetItem(result.value("guestlastname").toString()));
        ui->booking_table->setItem(row_num, 5, new QTableWidgetItem(result.value("startdate").toString()));
        ui->booking_table->setItem(row_num, 6, new QTableWidgetItem(result.value("enddate").toString()));


        QPushButton* button = new QPushButton(QString("Checkin/Undo"));
        ui->booking_table->setCellWidget(row_num, 7, button);

        //on delete button click, delete and refresh
        QObject::connect(button, &QPushButton::clicked, [ bookid, this]() {
            bq->flip_checkin(bookid);
            this->on_booking_find_booking_btn_clicked();
        });

        row_num++;
    }

}

void main_window::update_add_room_summary_table()
{
    //update add_booking_summary_table
    QSqlQuery result = bq->read_booking();
    int row_num = 0;

    ui->add_booking_summary_table->setRowCount(0);

    while (result.next()) {
        QString bookid;

        ui->add_booking_summary_table->setRowCount(row_num + 1);
        ui->add_booking_summary_table->setItem(row_num, 0, new QTableWidgetItem(bookid = result.value("bookid").toString()));

        QPushButton* button = new QPushButton(QString("Delete"));
        ui->add_booking_summary_table->setCellWidget(row_num, 1, button);

        //on delete button click, delete and refresh
        QObject::connect(button, &QPushButton::clicked, [ bookid, this]() {
            bq->delete_booking(bookid);
            this->update_add_room_summary_table();
        });

        row_num++;
    }


}

