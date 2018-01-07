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
}


#endif