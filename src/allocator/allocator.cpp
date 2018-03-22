#include "allocator.h"


namespace lithe {
    allocator::allocator(
        const lithe::buffer& buff_,
        const std::vector<size_t>& sizes_,
        const std::vector<size_t>& starting_
    ):
        buff(buff_),
        sizes(sizes_),
        starting(starting_),
        entity_size(std::accumulate(sizes.begin(), sizes.end(), size_t{0}))
    {

    }


    void allocator::swap(
        lithe::entity_id a,
        lithe::entity_id b
    ) {
        char* tmp = static_cast<char*>(::operator new(entity_size));

        std::copy(
            buff.buff + (entity_size * a),
            buff.buff + (entity_size * a) + entity_size,
            tmp
        );

        std::copy(
            buff.buff + (entity_size * b),
            buff.buff + (entity_size * b) + entity_size,
            buff.buff + (entity_size * a)
        );

        std::copy(
            tmp,
            tmp + entity_size,
            buff.buff + (entity_size * b)
        );

        delete tmp;
    }
}