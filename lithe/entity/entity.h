#ifndef LITHE_ENTITY_H
#define LITHE_ENTITY_H


#include <iostream>
#include "../constants.h"
#include "../types.h"
#include "../container/container.h"


namespace lithe {
    // A simple wrapper around a container that stores
    // an ID and implements wrapper functions that call
    // to the container object.
    struct entity {
        lithe::entity_id uid;
        lithe::container& container;


        entity(lithe::entity_id uid_, lithe::container& container_):
            uid(uid_),
            container(container_)
        {

        }


        // Get a reference to a component.
        template <typename T>
        T& get() const {
            return container.get<T>(uid);
        }


        // Check if this entity has a certain component.
        template <typename... Ts>
        bool has() const {
            return container.has<Ts...>(uid);
        }


        // Attach a component.
        template <typename... Ts>
        void attach(const Ts&&... ts) {
            container.attach<Ts...>(uid, ts...);
        }


        // Detach a component.
        template <typename... Ts>
        void detach() {
            container.detach<Ts...>(uid);
        }


        // Swap a component with another entity.
        template <typename T>
        void swap_component(const lithe::entity& other) {
            container.swap_component<T>(uid, other.uid);
        }


        // Swap all the components of this entity with another entity.
        void swap(const lithe::entity& other) {
            container.swap(uid, other.uid);
        }
    };
}


// Allow the user to print an entity object.
std::ostream& operator<<(std::ostream& os, const lithe::entity& entity) {
    os << entity.uid;
    return os;
}


#endif