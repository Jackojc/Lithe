#ifndef LITHE_DEFAULT_COMPONENTS_H
#define LITHE_DEFAULT_COMPONENTS_H


#include "../types.h"
#include "component.h"


namespace lithe {
    struct metadata: lithe::component<metadata> {
        lithe::bitmask tag;
    };
}


#endif