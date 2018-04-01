#ifndef LITHE_MEMORY_H
#define LITHE_MEMORY_H


#include <new>
#include <cstddef>
#include "types.h"


namespace lithe {
    // Creates a buffer on the heap using ::operator new.
    // Simply a convenience wrapper to create n number of
    // x sized entities. also converts to a char ptr instead
    // of just a raw void ptr.
    inline char* create_buffer(size_t chunk_size, lithe::entity_id num_entities) {
        void* ptr = nullptr;

        try {
            ptr = new char[chunk_size * num_entities]();

        } catch (const std::bad_alloc&) {
            // Do nothing if we fail to allocate memory, the user can check
            // manually by doing "if ptr == nullptr".
			return static_cast<char*>(ptr);
        }

        return static_cast<char*>(ptr);
    }


    // Free a buffer.
    inline void destroy_buffer(char* ptr) {
        // Make sure we aren't trying to free a nullptr.
        if (ptr != nullptr)
            ::operator delete[] (static_cast<void*>(ptr));
    }
}


#endif