#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <vector>
#include <numeric>
#include <cstddef>
#include "types.h"
#include "order.h"
#include "memory.h"
#include "allocator/allocator.h"
#include "container/container.h"
#include "info/info.h"
#include "world/world.h"


namespace lithe {
    // Get the size of each element in a variadic template
    // and put them into an array.
    template <typename... Ts>
    inline std::vector<size_t> get_sizes() {
        return {sizeof(Ts)...};
    }


    // Gets the starting position of each
    // type in the template.
    inline std::vector<size_t> get_origins(const std::vector<size_t>& sizes) {
        std::vector<size_t> start(sizes.size());

        for (size_t i = 0; i < sizes.size(); ++i)
            start[i] = std::accumulate(sizes.begin(), sizes.begin() + i, size_t{0});

        return start;
    }


    // Get the size (in bytes) of a collection of components.
    inline size_t get_total(const std::vector<size_t>& sizes) {
        return std::accumulate(sizes.begin(), sizes.end(), size_t{0});
    }


    // Set everything that we need up properly.
    template <typename... Ts>
    inline lithe::info setup_info(
        const lithe::component_group<Ts...>&,
        lithe::entity_id num_entities
    ) {
        lithe::info info;


        lithe::order_types<lithe::metadata, Ts...>();


        // Information about the components.
        info.sizes = lithe::get_sizes<
            lithe::metadata,  // this component is implicitly attached.
            Ts...
        >();

        info.origins = lithe::get_origins(info.sizes);
        info.entity_size = lithe::get_total(info.sizes);
        info.num_entities = num_entities;

        return info;
    }


    // Creates a buffer in which to store all the components.
    // We let the user provide their own handler for creating
    // the buffer because we're such nice people.

    // It's still up to the user to manually destroy the buffer later.
    inline lithe::buffer& setup_buffer(
        lithe::info& info,
        lithe::handler_create handler_c = &lithe::create_buffer,
        lithe::handler_destroy handler_d = &lithe::destroy_buffer
    ) {
        info.buffer = std::shared_ptr<char>(
            handler_c(info.entity_size, info.num_entities),
            handler_d
        );
        return info.buffer;
    }


    // Initialises the allocator object inside the info struct
    // and returns a reference to it.
    inline lithe::allocator& setup_allocator(lithe::info& info) {
        info.allocator = lithe::allocator(
            info.buffer,
            &info.sizes,
            &info.origins,
            info.entity_size
        );
        return info.allocator;
    }


    // Initialises the container object inside the info struct
    // and returns a reference to it.
    inline lithe::container& setup_container(lithe::info& info) {
        info.container = lithe::container(&info.allocator);
        return info.container;
    }


    inline lithe::uid_manager& setup_uid_manager(lithe::info& info) {
        return info.uids;
    }


    inline lithe::world& setup_world(lithe::info& info) {
        info.world = lithe::world(&info.container, &info.uids);
        return info.world;
    }
}


#endif


