#ifndef LITHE_SYSTEM_H
#define LITHE_SYSTEM_H


#include "../types.h"
#include "../entity/entity.h"
#include "../container/container.h"


namespace lithe {
    struct system {
        lithe::bitmask tag;

        template <typename... Ts>
        system(const lithe::component_group<Ts...>&):
            tag(lithe::create_bitmask(lithe::get_type_uids<Ts...>()))
        {

        }

        virtual ~system() {}


        virtual void update(lithe::entity&& entity) = 0;


        void update_entities(
            lithe::entity_id entity,
            lithe::container& container
        ) {
            update(lithe::entity{entity, container});
        }
    };
}


#endif