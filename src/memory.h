#ifndef LITHE_MEMORY_H
#define LITHE_MEMORY_H


#include <cstddef>


// Creates a buffer on the heap using ::operator new.
// Simply a convenience wrapper to create n number of
// x sized entities. also converts to a char ptr instead
// of just a raw void ptr.
inline char* create_buffer(size_t chunk_size, int num_entities) {
    return static_cast<char*>(::operator new(chunk_size * num_entities));
}


inline void destroy_buffer(char* buffer) {
    ::operator delete(static_cast<void*>(buffer));
}


#endif