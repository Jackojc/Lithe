#ifndef LITHE_CORE_H
#define LITHE_CORE_H


#include "../types.h"
#include "../uid_manager/uid_manager.h"
#include "../container/container.h"


namespace lithe {
    // Holds the core objects related to the engine.
    struct core {
        const lithe::info& info;
        lithe::uid_manager uids;
        lithe::container container;

        core(
            lithe::buffer& buff,
            const lithe::info& info_
        ):
            info(info_),
            uids(info_),
            container(buff, info_)
        {

        }
    };
}


#endif