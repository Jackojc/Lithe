#ifndef LITHE_INFO_H
#define LITHE_INFO_H


#include <cstddef>
#include <vector>


namespace lithe {
    struct info {
        std::vector<size_t> sizes;
        std::vector<int> origins;
        size_t chunk_size;


        info();
    };
}


#endif