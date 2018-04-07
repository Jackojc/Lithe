#ifndef LITHE_INFO_H
#define LITHE_INFO_H


#include "../types.h"
#include "../utils.h"
#include "../order.h"


namespace lithe {
    struct info {
        // Info in relation to all the components
        // that are going to be stored in this world.
        lithe::component_sizes   sizes;
        lithe::entity_id         num_entities;
        lithe::component_origins origins;
        lithe::entity_size       entity_size;


        // Get all info in relation to the components
        // that are going to be stored in the buffer.
        template <typename... Ts1, typename... Ts2>
        info(
            lithe::entity_id num_entities_,
            const lithe::component_group<Ts1...>&, // User defined.
            const lithe::component_group<Ts2...>&  // Implicit components.
        ):
            sizes(lithe::get_component_sizes<Ts2..., Ts1...>()),
            num_entities(num_entities_)
        {
            origins = lithe::get_component_origins(sizes);
            entity_size = lithe::get_entity_size(sizes);

            // Assign IDs to the components properly.
            lithe::order_types<Ts2..., Ts1...>();
        }
    };
}


#endif