#ifndef LITHE_DEFAULT_COMPONENTS_H
#define LITHE_DEFAULT_COMPONENTS_H


#include "../types.h"
#include "component.h"


namespace lithe {
    // Components included by default.
    struct metadata: lithe::component {
        lithe::bitmask tag;
    };
}


#endif