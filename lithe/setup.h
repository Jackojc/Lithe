#ifndef LITHE_SETUP_H
#define LITHE_SETUP_H


#include "types.h"
#include "info/info.h"
#include "core/core.h"
#include "world/world.h"


namespace lithe {
    // Function that creates a core object.
    inline lithe::core create_core(
        lithe::buffer& buff,
        const lithe::info& info
    ) {
        return {buff, info};
    }


    // Set everything that we need up properly.
    inline lithe::world create_world(lithe::core& core) {
        return {core.info, core.container};
    }
}


#endif