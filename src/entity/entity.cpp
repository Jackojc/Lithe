#include "entity.h"


namespace lithe {
    entity::entity(const lithe::entity_id uid_, lithe::container& container_):
        uid(uid_),
        container(container_),
        component_mask()
    {

    }


    // Swap the components of this entity with another one.
    void entity::swap(lithe::entity_id other) {
        container.swap(uid, other);
    }
}
