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
        const lithe::entity_id uid;
        lithe::container& container;
        std::bitset<64> component_mask;


        entity(const lithe::entity_id uid_, lithe::container& container_);


        // Attach a component.
        template <typename T>
        void attach(const T& item) {
            component_mask[lithe::get_type_uid<T>()] = true;
            container.attach<T>(uid, item);
        }


        // Convenience wrapper to allow you to attach
        // multiple components in one call.
        template<typename T, typename... Ts>
        void attach(const T& t, const Ts&&... ts) {
            attach(t);
            attach<Ts...>(ts...);
        }


        // Detach a component.
        template <typename T>
        void detach() {
            container.detach<T>(uid);
            component_mask[lithe::get_type_uid<T>()] = false;
        }


        // Convenience wrapper to allow you to
        // detach multiple components in one call.
        template <typename T1, typename T2, typename... Ts>
        void detach() {
            detach<T1>(uid);
            detach<T2, Ts...>(uid);
        }


        // Check if this entity has a certain component.
        template <typename T>
        bool has() const {
            return component_mask[lithe::get_type_uid<T>()];
        }


        // Get a reference to a component.
        template <typename T>
        T& get() const {
            return container.get<T>(uid);
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