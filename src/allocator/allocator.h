#ifndef LITHE_ALLOCATOR_H
#define LITHE_ALLOCATOR_H


#include <vector>
#include <cstddef>
#include <new>
#include <algorithm>
#include "../utils.h"
#include "../translate_index.h"
#include "../buffer/buffer.h"


namespace lithe {
    // Allocates and manipulates a
    // buffer of objects.
    struct allocator {
        const buffer& buff;
        const std::vector<size_t>& sizes;
        size_t entity_size;
        const std::vector<int>& starting;


        // These arrays must be passed by value or else
        // we get a segmentation fault for trying to
        // access variables that have since gone out of
        // scope.
        allocator(
            const buffer& buff,
            const std::vector<size_t>& sizes_,
            const std::vector<int>& starting_
        );


        // Insert an object to a buffer.
        template <typename T>
        T& insert(int x, int y, const T& item);


        // Get an object by reference from the buffer.
        // This function allows you to get the object
        // - both by val and by ref.
        // e.g: auto& (ref) or auto (val).
        template <typename T>
        T& get(int x, int y);


        // Value initialises a region of the buffer.
        template <typename T>
        void zero(int x, int y);
    };
}


#endif