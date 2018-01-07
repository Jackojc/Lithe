#ifndef LITHE_COMPONENT_CONTAINER_CPP
#define LITHE_COMPONENT_CONTAINER_CPP


#include "component_container.h"


namespace lithe {
    component_container::component_container(allocator& alloc_):
        alloc(alloc_)
    {
        alive.resize(alloc_.sizes.size() * alloc.buff.num_entities);
    }


    // Removes a component from an entity.
    template <typename T>
    void component_container::remove(int entity, const T& item) {
        alloc.zero(get_type_id<T>(), entity);

        alive[
            translate_index(alloc.entity_size, get_type_id<T>(), entity)
        ] = false;
    }


    // Checks if an entity has a component.
    template <typename T>
    bool component_container::has(int entity) {
        return alive[
            translate_index(alloc.entity_size, get_type_id<T>(), entity)
        ];
    }
}


#endif