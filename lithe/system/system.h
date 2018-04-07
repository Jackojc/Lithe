#ifndef LITHE_SYSTEM_H
#define LITHE_SYSTEM_H


#include "../types.h"
#include "../bitmask.h"
#include "../entity/entity.h"
#include "../container/container.h"


namespace lithe {
    struct system {
        lithe::bitmask tag;

        // Assign a tag to the system
        // so we know what components
        // it operates on.
        template <typename... Ts>
        system(const lithe::component_group<Ts...>&):
            tag(lithe::create_bitmask(lithe::get_component_uids<Ts...>()))
        {

        }

        virtual ~system() {}


        // Member function that is
        // overridden by the user.
        virtual void update(lithe::entity&& entity) = 0;
    };
}


#endif