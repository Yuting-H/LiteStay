#include "window_manager.h"
#include "main_window.h"

//declare pointer to windows on global scope so they dont dissapear
main_window *w = nullptr;

//constructor for window manager
window_manager::window_manager() {
    w = new main_window();
    w->show();
}
