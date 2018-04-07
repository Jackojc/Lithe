#ifndef LITHE_MEMORY_H
#define LITHE_MEMORY_H


#include <new>
#include <cstddef>
#include "types.h"
#include "info/info.h"


namespace lithe {
    // Free a buffer.
    inline void destroy_buffer(lithe::buffer_type ptr) {
        // Make sure we aren't trying to free a nullptr.
        if (ptr != nullptr)
            delete[] ptr;
    }


    // Creates a buffer on the heap using ::operator new.
    // Simply a convenience wrapper to create n number of
    // x sized entities. also converts to a char ptr instead
    // of just a raw void ptr.
    inline lithe::buffer create_buffer(const lithe::info& info) {
        void* ptr = nullptr;

        try {
            ptr = new char[info.entity_size * info.num_entities]();

        } catch (const std::bad_alloc&) {
            // Do nothing if we fail to allocate memory, the user can check
            // manually by doing "if ptr == nullptr".
        }


        return lithe::buffer(
            static_cast<lithe::buffer_type>(ptr),
            &lithe::destroy_buffer
        );
    }
}


#endif