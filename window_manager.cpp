#include "window_manager.h"
#include "main_window.h"
#include "login_window.h"

/*!
 * \brief managers the windows and qt connections
 */
//declare pointer to windows on global scope so they dont dissapear
main_window *m = nullptr;
login_window *l = nullptr;

//constructor for window manager
window_manager::window_manager() {

    //creates login and main window
    l = new login_window();
    l->show();
    m = new main_window();
    m->show();

    //connects
    QObject::connect(l, &login_window::login_request, l, &login_window::received_login_request);
    QObject::connect(l, &login_window::elevate_privilege, m, &main_window::elevate_privilege);
}
