#ifndef LITHE_COMPONENT_H
#define LITHE_COMPONENT_H


#include "../constants.h"
#include "../types.h"
#include "../uid.h"


namespace lithe {
    template <typename T>
    struct component {
        component() {

        }
    };


    template <typename... Ts>
    struct component_group {};
}


#endif