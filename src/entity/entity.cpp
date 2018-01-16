#ifndef LITHE_ENTITY_CPP
#define LITHE_ENTITY_CPP


#include "entity.h"


namespace lithe {
    entity::entity(uintmax_t uid_, lithe::component_container& container_):
        uid(uid_),
        container(container_)
    {

    }
}


#endif