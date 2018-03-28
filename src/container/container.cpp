#include "container.h"


namespace lithe {
    container::container(lithe::allocator* alloc_):
        alloc(alloc_)
    {

    }


    // Swap two entities. (and their components.)
    void container::swap(lithe::entity_id a, lithe::entity_id b) {
        alloc->swap(a, b);
    }
}