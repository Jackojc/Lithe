#ifndef LITHE_CONTAINER_H
#define LITHE_CONTAINER_H


#include <vector>
#include "../uid.h"
#include "../translate_index.h"
#include "../allocator/allocator.h"


namespace lithe {
    // Component interface.
    struct container {
        lithe::allocator& alloc;


        container(lithe::allocator& alloc_);


        // Attaches a component to a specified entity.
        template <typename T>
        T& insert(int entity, const T& item) {
            return alloc.insert(lithe::get_type_uid<T>(), entity, item);
        }


        // Removes a component from an entity.
        template <typename T>
        void remove(int entity) {
            alloc.remove<T>(lithe::get_type_uid<T>(), entity);
            //alloc.zero<T>(lithe::get_type_uid<T>(), entity);
        }


        // Returns a reference to a component within an entity.
        template <typename T>
        T& get(int entity) {
            return alloc.get<T>(lithe::get_type_uid<T>(), entity);
        }
    };
}


#endif