#ifndef LITHE_INFO_H
#define LITHE_INFO_H


#include <cstddef>
#include <vector>
#include "../types.h"
#include "../allocator/allocator.h"
#include "../container/container.h"


namespace lithe {
    struct info {
        std::vector<size_t> sizes;
        std::vector<size_t> origins;
        size_t              entity_size;
        lithe::entity_id    num_entities;

        lithe::buffer    buffer;
        lithe::allocator allocator;
        lithe::container container;

        // Function pointer for cleaning up buffer.
        lithe::handler_destroy handler_destroy;


        info();
        ~info();


        lithe::buffer& get_buffer();
        lithe::allocator& get_allocator();
        lithe::container& get_container();
    };
}


#endif