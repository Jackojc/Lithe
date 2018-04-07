#ifndef LITHE_WORLD_H
#define LITHE_WORLD_H


#include "../container/container.h"
#include "../uid_manager/uid_manager.h"
#include "../system_manager/system_manager.h"
#include "../entity_manager/entity_manager.h"


namespace lithe {
    struct world:
        lithe::system_manager,
        lithe::entity_manager
    {
        world(
            lithe::container& container_,
            lithe::uid_manager& uids_
        ):
            lithe::entity_manager(uids_, container_)
        {

        }


        // Update all registered systems.
        void update() {
            update_systems(entities, container);
        }
    };
}


#endif