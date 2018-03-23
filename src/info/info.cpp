#include "info.h"


namespace lithe {
    // Ugly constructor fish.
    info::info():
        sizes(),
        origins(),
        entity_size(1),
        num_entities(0),

        buffer(nullptr),
        allocator(nullptr, nullptr, nullptr, 1),
        container(nullptr),

        handler_destroy(nullptr)
    {

    }


    // Cleanup when we go out of scope.
    info::~info() {
        handler_destroy(buffer);
    }


    // Getters.
    lithe::buffer& info::get_buffer() {
        return buffer;
    }


    lithe::allocator& info::get_allocator() {
        return allocator;
    }


    lithe::container& info::get_container() {
        return container;
    }
}