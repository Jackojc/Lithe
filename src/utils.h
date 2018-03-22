#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <vector>
#include <numeric>
#include <cstddef>
#include "order.h"
#include "types.h"
#include "memory.h"
#include "allocator/allocator.h"
#include "container/container.h"
#include "info/info.h"


namespace lithe {
    // Get the size of each element in a variadic template
    // and put them into an array.
    template <typename... types>
    inline std::vector<size_t> get_sizes() {
        lithe::order_types<types...>();
        return {sizeof(types)...};
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
    template <typename... TArgs>
    inline lithe::info setup_info(
        lithe::entity_id num_entities,

        lithe::handler_create handle_c = &lithe::create_buffer,
        lithe::handler_destroy handle_d = &lithe::destroy_buffer
    ) {
        lithe::info x;

        // Information about the components.
        x.sizes = lithe::get_sizes<TArgs...>();
        x.origins = lithe::get_origins(x.sizes);
        x.entity_size = lithe::get_total(x.sizes);
        x.num_entities = num_entities;

        // Objects to facilitate the manipulation of components.
        x.buffer = handle_c(x.entity_size, x.num_entities);
        x.handler_destroy = handle_d;

        x.allocator = lithe::allocator(x.buffer, &x.sizes, &x.origins, x.entity_size);
        x.container = lithe::container(&x.allocator);

        return x;
    }
}


#endif


