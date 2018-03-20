#include "scene.h"


namespace lithe {
    // These functions wrap the call to the virtual functions
    // implemented by the user.
    // Handy if you want to add logging or something.
    void scene::internal_event() {
        event();
    }


    void scene::internal_update() {
        update();
    }


    void scene::internal_draw() {
        draw();
    }


    // Calls all the wrapper functions and in turn
    // the functions the user has implemented.
    void scene::update_all() {
        internal_event();
        internal_update();
        internal_draw();
    }
}