#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <vector>
#include <numeric>
#include <cstddef>
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
    inline lithe::info setup_info(lithe::entity_id num_entities) {
        lithe::info info;

        // Information about the components.
        info.sizes = lithe::get_sizes<TArgs...>();
        info.origins = lithe::get_origins(info.sizes);
        info.entity_size = lithe::get_total(info.sizes);
        info.num_entities = num_entities;

        return info;
    }


    inline lithe::buffer& setup_buffer(
        lithe::info& info,
        lithe::handler_create handler = &lithe::create_buffer
    ) {
        info.buffer = handler(info.entity_size, info.num_entities);
        return info.buffer;
    }


    inline lithe::allocator& setup_allocator(lithe::info& info) {
        info.allocator = lithe::allocator(
            info.buffer,
            &info.sizes,
            &info.origins,
            info.entity_size
        );
        return info.allocator;
    }


    inline lithe::container& setup_container(lithe::info& info) {
        info.container = lithe::container(&info.allocator);
        return info.container;
    }
}


#endif


