#include "allocator.h"


namespace lithe {
    allocator::allocator(
        lithe::buffer buff_,
        std::vector<size_t>* sizes_,
        std::vector<size_t>* starting_,
        size_t entity_size_
    ):
        buff(buff_),
        sizes(sizes_),
        starting(starting_),
        entity_size(entity_size_)
    {

    }


    void allocator::swap(
        lithe::entity_id a,
        lithe::entity_id b
    ) {
        char* tmp = static_cast<char*>(::operator new(entity_size));

        std::copy(
            buff + (entity_size * a),
            buff + (entity_size * a) + entity_size,
            tmp
        );

        std::copy(
            buff + (entity_size * b),
            buff + (entity_size * b) + entity_size,
            buff + (entity_size * a)
        );

        std::copy(
            tmp,
            tmp + entity_size,
            buff + (entity_size * b)
        );

        delete tmp;
    }
}