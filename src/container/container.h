#ifndef LITHE_CONTAINER_H
#define LITHE_CONTAINER_H


#include <vector>
#include "../types.h"
#include "../uid.h"
#include "../translate_index.h"
#include "../allocator/allocator.h"


namespace lithe {
    // Component interface.
    struct container {
        lithe::allocator* alloc;


        container(lithe::allocator* alloc_);


        // Attaches a component to a specified entity.
        template <typename T>
        T& insert(lithe::entity_id entity, const T& item) {
            return alloc->insert(lithe::get_type_uid<T>(), entity, item);
        }


        // Returns a reference to a component within an entity.
        template <typename T>
        T& get(lithe::entity_id entity) const {
            return alloc->get<T>(lithe::get_type_uid<T>(), entity);
        }


        // Removes a component from an entity.
        template <typename T>
        void remove(lithe::entity_id entity) {
            alloc->remove<T>(lithe::get_type_uid<T>(), entity);
            //alloc->zero<T>(lithe::get_type_uid<T>(), entity);
        }


        template <typename T>
        void swap_component(lithe::entity_id a, lithe::entity_id b) {
            lithe::component_id tmp = lithe::get_type_uid<T>();
            alloc->swap_component<T>(tmp, a, tmp, b);
        }


        void swap(lithe::entity_id a, lithe::entity_id b);
    };
}


#endif