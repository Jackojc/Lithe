#ifndef LITHE_COMPONENT_CONTAINER_H
#define LITHE_COMPONENT_CONTAINER_H


#include <vector>
#include "../uid.h"
#include "../translate_index.h"
#include "../allocator/allocator.h"


namespace lithe {
    // Component interface.
    struct component_container {
        allocator& alloc;
        std::vector<char> alive;


        component_container(allocator& alloc_);


        // Attaches a component to a specified entity.
        template <typename T>
        T& insert(int entity, const T& item);


        // Removes a component from an entity.
        template <typename T>
        void remove(int entity, const T& item);


        // Checks if an entity has a component.
        template <typename T>
        bool has(int entity);


        // Returns a reference to a component within an entity.
        template <typename T>
        T& get(int entity);
    };
}


#endif