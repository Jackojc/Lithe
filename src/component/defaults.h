#ifndef LITHE_DEFAULT_COMPONENTS_H
#define LITHE_DEFAULT_COMPONENTS_H


#include "../types.h"
#include "component.h"


namespace lithe {
    struct metadata: lithe::component<metadata> {
        lithe::bitmask bits;
    };


    static lithe::component_group<lithe::metadata> IMPLICIT_COMPONENTS;
}


#endif