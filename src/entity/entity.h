#ifndef LITHE_ENTITY_H
#define LITHE_ENTITY_H


#include <iostream>
#include <bitset>
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


        entity(lithe::entity_id uid_, lithe::container& container_);


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
        void swap_component(lithe::entity_id other) {
            container.swap_component<T>(uid, other);
        }


        // Swap all the components of this entity with another entity.
        void swap(lithe::entity_id other);
    };
}


#endif