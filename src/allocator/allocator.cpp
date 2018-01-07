#ifndef LITHE_ALLOCATOR_CPP
#define LITHE_ALLOCATOR_CPP


#include "allocator.h"


namespace lithe {
    allocator::allocator(
        const buffer& buff_,
        const std::vector<size_t>& sizes_,
        const std::vector<int>& starting_
    ):
        buff(buff_),
        sizes(sizes_),
        starting(starting_)
    {

    }


    // Insert an object to a buffer.
    template <typename T>
    T& allocator::insert(int x, int y, const T& item) {
        int i = translate_index(buff.chunk_size, x, y);
        return *(new (buff.buff + (i + sizes[x])) T{item});
    }


    // Get an object by reference from the buffer.
    // This function allows you to get the object
    // - both by val and by ref.
    // e.g: auto& (ref) or auto (val).
    template <typename T>
    T& allocator::get(int x, int y) {
        int i = translate_index(buff.chunk_size, x, y);
        return *static_cast<T*>(
            static_cast<void*>(
                buff.buff + (i + sizes[x])
            )
        );
    }


    // Value initialises a region of the buffer.
    template <typename T>
    void allocator::zero(int x, int y) {
        std::fill_n(buff, sizeof(T), 0);
    }
}


#endif