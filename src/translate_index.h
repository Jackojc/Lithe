#ifndef LITHE_TRANSLATE_INDEX_H
#define LITHE_TRANSLATE_INDEX_H


namespace lithe {
    // Translate 2d coordinates to 1d for use in
    // indexing the buffer of memory that stores
    // the components.
    inline int translate_index(int block_size, int x, int y) {
        return block_size * y + x;
    }
}


#endif
