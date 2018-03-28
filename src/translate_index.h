#ifndef LITHE_TRANSLATE_INDEX_H
#define LITHE_TRANSLATE_INDEX_H


#include "types.h"


namespace lithe {
    // Translate 2d coordinates to 1d for use in
    // indexing the buffer of memory that stores
    // the components.
    inline size_t translate_index(
        size_t block_size, 
        lithe::component_id x, 
        lithe::entity_id y
    ) {
        return block_size * y + x;
    }
}


#endif
