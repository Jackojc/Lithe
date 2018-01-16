#ifndef LITHE_COMPONENT_CONTAINER_CPP
#define LITHE_COMPONENT_CONTAINER_CPP


#include "component_container.h"


namespace lithe {
    component_container::component_container(allocator& alloc_):
        alloc(alloc_)
    {
        alive.resize(alloc_.sizes.size() * alloc.buff.num_entities);
    }
}


#endif