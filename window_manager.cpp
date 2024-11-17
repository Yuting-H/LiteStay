#include "window_manager.h"
#include "main_window.h"
#include "login_window.h"

/*!
 * \brief managers the windows and qt connections
 */
//declare pointer to windows on global scope so they dont dissapear
main_window *w = nullptr;
login_window *l = nullptr;

//constructor for window manager
window_manager::window_manager() {

    l = new login_window();
    //l->show();
    w = new main_window();
    w->show();
}
