#ifndef LITHE_ENTITY_MANAGER_H
#define LITHE_ENTITY_MANAGER_H


#include "../types.h"
#include "../info/info.h"
#include "../uid_manager/uid_manager.h"
#include "../container/container.h"
#include "../entity/entity.h"


namespace lithe {
    // Class that handles creation and
    // destruction of entity objects.
    struct entity_manager: lithe::uid_manager {
        lithe::entity_ids entities;
        lithe::container& container;


        entity_manager(
            const lithe::info& info_,
            lithe::container& container_
        ):
            lithe::uid_manager(info_),
            container(container_)
        {

        }


        // Create a unique ID and then
        // assign it to an entity object
        // and return it.
        lithe::entity create() {
            lithe::entity_id entity = withdraw();
            entities.insert(entity);
            return {entity, container};
        }


        // Destroy an entity ID.
        void destroy(const lithe::entity& entity) {
            entities.erase(entity.uid);
            deposit(entity.uid);
        }
    };
}


#endif
