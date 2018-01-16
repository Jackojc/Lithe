#ifndef LITHE_ENTITY_H
#define LITHE_ENTITY_H


#include <cstdint>
#include "../component_container/component_container.h"


namespace lithe {
    // A simple wrapper around a container that stores
    // an ID and implements wrapper functions that call
    // to the container object.
    struct entity {
        uintmax_t uid;
        lithe::component_container& container;


        entity(uintmax_t uid_, lithe::component_container& container_);


        // Insert a component.
        template <typename T>
        T& insert(const T& item) {
            return container.insert<T>(uid, item);
        }


        // Remove a component.
        template <typename T>
        void remove() {
            container.remove<T>(uid);
        }


        // Check if this entity has a certain component.
        template <typename T>
        bool has() {
            return container.has<T>(uid);
        }


        // Get a reference to a component.
        template <typename T>
        T& get() {
            return container.get<T>(uid);
        }
    };
}


#endif