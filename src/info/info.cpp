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
        uids(),
        world(nullptr, nullptr)
    {

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


    lithe::uid_manager& info::get_uid_manager() {
        return uids;
    }


    lithe::world& info::get_world() {
        return world;
    }
}