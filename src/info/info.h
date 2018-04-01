#ifndef LITHE_INFO_H
#define LITHE_INFO_H


#include <memory>
#include <cstddef>
#include <vector>
#include "../types.h"
#include "../allocator/allocator.h"
#include "../container/container.h"
#include "../uid_manager/uid_manager.h"
#include "../world/world.h"


namespace lithe {
    struct info {
        // Info in relation to all the components
        // that are going to be stored in this world.
        std::vector<size_t> sizes;
        std::vector<size_t> origins;
        size_t              entity_size;
        lithe::entity_id    num_entities;

        // Keep all core components inside this object.
        lithe::buffer      buffer;
        lithe::allocator   allocator;
        lithe::container   container;
        lithe::uid_manager uids;
        lithe::world       world;


        info();


        // Getters.
        lithe::buffer& get_buffer();
        lithe::allocator& get_allocator();
        lithe::container& get_container();
        lithe::uid_manager& get_uid_manager();
        lithe::world& get_world();
    };
}


#endif