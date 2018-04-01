#ifndef LITHE_SYSTEM_TAG_H
#define LITHE_SYSTEM_TAG_H


#include "../types.h"
#include "../utils.h"


namespace lithe {
    template <typename... Ts>
    struct system_tag {
        lithe::bitmask tag;

        system_tag():
            tag(lithe::create_bitmask(lithe::get_type_uids<Ts...>()))
        {

        }
    };
}


#endif