#ifndef LITHE_ENTITY_MANAGER_H
#define LITHE_ENTITY_MANAGER_H


#include "../types.h"
#include "../uid_manager/uid_manager.h"
#include "../container/container.h"
#include "../entity/entity.h"


namespace lithe {
    // Class that handles creation and
    // destruction of entity objects.
    struct entity_manager {
        lithe::entity_ids entities;
        lithe::uid_manager& uids;
        lithe::container& container;


        entity_manager(
            lithe::uid_manager& uids_,
            lithe::container& container_
        ):
            uids(uids_),
            container(container_)
        {

        }


        // Create a unique ID and then
        // assign it to an entity object
        // and return it.
        lithe::entity create() {
            lithe::entity_id entity = uids.withdraw();
            entities.insert(entity);
            return {entity, container};
        }


        // Destroy an entity ID.
        void destroy(const lithe::entity& entity) {
            entities.erase(entity.uid);
        }
    };
}


#endif
