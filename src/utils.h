#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <vector>
#include <numeric>
#include <cstddef>
#include "order.h"


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
    inline std::vector<int> get_origins(const std::vector<size_t>& sizes) {
        std::vector<int> start(sizes.size());

        for (size_t i = 0; i < sizes.size(); ++i)
            start[i] = std::accumulate(sizes.begin(), sizes.begin() + i, 0);

        return start;
    }


    // Get the size (in bytes) of a collection of components.
    inline size_t get_total(const std::vector<size_t>& sizes) {
        return std::accumulate(sizes.begin(), sizes.end(), 0);
    }
}


#endif


