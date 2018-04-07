#ifndef LITHE_COMPONENT_H
#define LITHE_COMPONENT_H


#include "../constants.h"
#include "../types.h"
#include "../uid.h"


namespace lithe {
    // Mainly used for type safety when
    // attaching components to entities.
    struct component {
        component() {

        }
    };
}


#endif