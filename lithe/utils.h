#ifndef LITHE_UTILS_H
#define LITHE_UTILS_H


#include <numeric>
#include "types.h"
#include "component/defaults.h"


namespace lithe {
    // Get the size of each element in a variadic template
    // and put them into an array.
    template <typename... Ts>
    inline lithe::component_sizes get_component_sizes() {
        return {sizeof(Ts)...};
    }


    // Gets the starting position of each
    // type in the template.
    inline lithe::component_origins get_component_origins(
        const lithe::component_sizes& sizes
    ) {
        lithe::component_origins origins(sizes.size());

        for (lithe::component_size i = 0; i < sizes.size(); ++i)
            origins[i] = std::accumulate(
                sizes.begin(),
                sizes.begin() + i,
                lithe::component_size{0}
            );

        return origins;
    }


    // Get the size (in bytes) of a collection of components.
    inline lithe::entity_size get_entity_size(
        const lithe::component_sizes& sizes
    ) {
        return std::accumulate(
            sizes.begin(),
            sizes.end(),
            lithe::entity_size{0}
        );
    }


    // Get a group of implicitly attached components.
    inline decltype(auto) get_implicit_components() {
        return lithe::component_group<lithe::metadata>{};
    }
}


#endif


