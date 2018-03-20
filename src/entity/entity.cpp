#include "entity.h"


namespace lithe {
    entity::entity(lithe::component_id uid_, lithe::container& container_):
        uid(uid_),
        container(container_),
        component_mask{}
    {

    }
}
