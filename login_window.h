#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class login_window;
}

class login_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit login_window(QWidget *parent = nullptr);
    ~login_window();

public: signals:


private:
    Ui::login_window *ui;
};

#endif // LOGIN_WINDOW_H
