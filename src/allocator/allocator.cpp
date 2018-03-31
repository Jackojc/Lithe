#include "allocator.h"


namespace lithe {
    allocator::allocator(
        lithe::buffer buff_,
        std::vector<size_t>* sizes_,
        std::vector<size_t>* origins_,
        size_t entity_size_
    ):
        buff(buff_),
        sizes(sizes_),
        origins(origins_),
        entity_size(entity_size_)
    {

    }


    // Swap two entities. (and their components.)
    void allocator::swap(
        lithe::entity_id a,
        lithe::entity_id b
    ) {
        // Create temporary buffer.
        char* tmp = static_cast<char*>(::operator new(entity_size));

        // Copy A into TMP.
        std::copy(
            buff.get() + (entity_size * a),
            buff.get() + (entity_size * a) + entity_size,
            tmp
        );

        // Copy B into A.
        std::copy(
            buff.get() + (entity_size * b),
            buff.get() + (entity_size * b) + entity_size,
            buff.get() + (entity_size * a)
        );

        // Copy TMP into B.
        std::copy(
            tmp,
            tmp + entity_size,
            buff.get() + (entity_size * b)
        );

        // Delete temporary buffer.
        delete tmp;
    }
}