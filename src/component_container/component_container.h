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
        T& insert(int entity, const T& item) {
            alive[
                translate_index(
                    alloc.entity_size,
                    lithe::get_type_uid<T>(),
                    entity
                )
            ] = true;

            return alloc.insert(lithe::get_type_uid<T>(), entity, item);
        }


        // Removes a component from an entity.
        template <typename T>
        void remove(int entity) {
            alloc.remove<T>(lithe::get_type_uid<T>(), entity);
            alloc.zero(lithe::get_type_uid<T>(), entity);

            alive[
                translate_index(alloc.entity_size, lithe::get_type_uid<T>(), entity)
            ] = false;
        }


        // Checks if an entity has a component.
        template <typename T>
        bool has(int entity) {
            return alive[
                translate_index(alloc.entity_size, lithe::get_type_uid<T>(), entity)
            ];
        }


        // Returns a reference to a component within an entity.
        template <typename T>
        T& get(int entity) {
            return alloc.get<T>(lithe::get_type_uid<T>(), entity);
        }
    };
}


#endif