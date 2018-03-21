#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <vector>
#include <numeric>
#include <cstddef>
#include "order.h"
#include "buffer/buffer.h"
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


    template <typename... TArgs>
    inline lithe::info get_info() {
        lithe::info x;

        x.sizes = lithe::get_sizes<TArgs...>();
        x.origins = lithe::get_origins(x.sizes);
        x.chunk_size = lithe::get_total(x.sizes);

        return x;
    }


    inline lithe::buffer setup_buffer(const lithe::info& x, unsigned num) {
        return {x.chunk_size, num};
    }


    inline lithe::allocator setup_allocator(
        const lithe::info& x,
        const lithe::buffer& buff
    ) {
        return {buff, x.sizes, x.origins};
    }


    inline lithe::container setup_container(
        lithe::allocator& alloc
    ) {
        return {alloc};
    }
}


#endif


