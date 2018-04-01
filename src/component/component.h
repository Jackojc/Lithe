#ifndef LITHE_COMPONENT_H
#define LITHE_COMPONENT_H


#include "../constants.h"
#include "../types.h"
#include "../uid.h"


namespace lithe {
    // Uses the CRTP to determine type ids at construction.

    // Components have members with an id when in debug mode.
    #ifdef LITHE_DEBUG_FLAG
        template <typename T>
        struct component {
            lithe::component_id type_id;

            component():
                type_id(lithe::get_type_uid<T>())
            {

            }
        };

    // If we are in release, we dont want added bloat
    // from lithe::component_id.
    #else
        template <typename T>
        struct component {
            component() {
                lithe::get_type_uid<T>();
            }
        };
    #endif


    template <typename... Ts>
    struct component_group {};
}


#endif