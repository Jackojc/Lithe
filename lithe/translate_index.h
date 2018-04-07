#ifndef LITHE_TRANSLATE_INDEX_H
#define LITHE_TRANSLATE_INDEX_H


#include "types.h"
#include "info/info.h"


namespace lithe {
    // Translate 2d coordinates to 1d for use in
    // indexing the buffer of memory that stores
    // the components.
    inline lithe::buffer_type translate_index(
        const lithe::buffer& buff,
        const lithe::info& info,
        lithe::component_id x,
        lithe::entity_id y
    ) {
        return buff.get() + ((info.entity_size * y + info.origins[x]));
    }
}


#endif
