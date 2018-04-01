#include "entity.h"


namespace lithe {
    entity::entity(lithe::entity_id uid_, lithe::container& container_):
        uid(uid_),
        container(container_)
    {

    }


    // Swap the components of this entity with another one.
    void entity::swap(lithe::entity_id other) {
        container.swap(uid, other);
    }
}


std::ostream& operator<<(std::ostream& os, const lithe::entity& entity) {
    os << entity.uid;
    return os;
}