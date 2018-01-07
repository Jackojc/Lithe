#ifndef LITHE_BUFFER_CPP
#define LITHE_BUFFER_CPP


#include "buffer.h"


namespace lithe {
    buffer::buffer(size_t chunk_size_, int num_entities_):
        chunk_size(chunk_size_),
        num_entities(num_entities_)
    {
        buff = create_buffer(chunk_size_, num_entities_);
    }


    buffer::~buffer() {
        destroy_buffer(buff);
    }
}


#endif