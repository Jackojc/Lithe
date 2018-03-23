#include "scene_manager.h"


namespace lithe {
    // Make sure to delete all objects on the stack so
    // we don't leak.
    scene_manager::~scene_manager() {
        for (size_t i = 0; i < objs.size(); ++i) {
            delete objs.top();
            objs.pop();
        }
    }


    // Remove a scene object and resume the one below it.
    void scene_manager::remove() {
        delete objs.top();

        objs.pop();

        if (!objs.empty())
            current().resume();
    }


    // Get the current scene.
    lithe::scene& scene_manager::current() const {
        return *objs.top();
    }


    // Update the current scene.
    void scene_manager::update() {
        if (!objs.empty())
            current().update_all();
    }
}