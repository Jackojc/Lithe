#ifndef LITHE_BITMASK_H
#define LITHE_BITMASK_H


#include <vector>
#include "types.h"


namespace lithe {
    // See if the system's tag is contained within
    // an entities tag.
    inline bool compare_bitmasks(
        const lithe::bitmask& entity,
        const lithe::bitmask& tag
    ) {
        return (
            (entity & tag) == tag
            && !entity.none()
        );
    }


    // create a bitmask from a container of uids.
    inline lithe::bitmask create_bitmask(
        const std::vector<lithe::component_id>& uids
    ) {
        lithe::bitmask bits;

        for (const auto& uid: uids) {
            bits[uid] = true;
        }

        return bits;
    }
}


#endif