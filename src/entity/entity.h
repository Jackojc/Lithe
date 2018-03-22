#ifndef LITHE_ENTITY_H
#define LITHE_ENTITY_H


#include <cmath>
#include <bitset>
#include "../types.h"
#include "../container/container.h"


namespace lithe {
    // A simple wrapper around a container that stores
    // an ID and implements wrapper functions that call
    // to the container object.
    struct entity {
        lithe::entity_id uid;
        lithe::container& container;
        std::bitset<64> component_mask;


        entity(lithe::entity_id uid_, lithe::container& container_);


        // Insert a component.
        template <typename T>
        T& insert(const T& item) {
            component_mask[lithe::get_type_uid<T>()] = 1;
            return container.insert<T>(uid, item);
        }


        // Remove a component.
        template <typename T>
        void remove() {
            container.remove<T>(uid);
            component_mask[lithe::get_type_uid<T>()] = 0;
        }


        // Check if this entity has a certain component.
        template <typename T>
        bool has() {
            return component_mask[lithe::get_type_uid<T>()];
        }


        // Get a reference to a component.
        template <typename T>
        T& get() {
            return container.get<T>(uid);
        }


        template <typename T>
        void swap_component(lithe::entity_id other) {
            container.swap_component<T>(uid, other);
        }


        void swap(lithe::entity_id other);
    };
}


#endif