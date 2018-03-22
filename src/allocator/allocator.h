#ifndef LITHE_ALLOCATOR_H
#define LITHE_ALLOCATOR_H


#include <vector>
#include <cstddef>
#include <new>
#include <algorithm>
#include <numeric>
#include "../translate_index.h"
#include "../types.h"


namespace lithe {
    // Allocates and manipulates a
    // buffer of objects.
    struct allocator {
        lithe::buffer buff;
        std::vector<size_t>* sizes;
        std::vector<size_t>* starting;
        size_t entity_size;


        // These arrays must be passed by value or else
        // we get a segmentation fault for trying to
        // access variables that have since gone out of
        // scope.
        allocator(
            lithe::buffer buff_,
            std::vector<size_t>* sizes_,
            std::vector<size_t>* starting_,
            size_t entity_size_
        );


        // Insert an object to a buffer.
        template <typename T>
        T& insert(lithe::component_id x, lithe::entity_id y, const T& item) {
            size_t i = lithe::translate_index(entity_size, x, y);

            return *(new (buff + (i + starting->at(x))) T{item});
        }


        // Get an object by reference from the buffer.
        // This function allows you to get the object
        // - both by val and by ref.
        // e.g: auto& (ref) or auto (val).
        template <typename T>
        T& get(lithe::component_id x, lithe::entity_id y) const {
            size_t i = lithe::translate_index(entity_size, x, y);

            return *static_cast<T*>(
                static_cast<void*>(buff + (i + starting->at(x)))
            );
        }


        template <typename T>
        void remove(lithe::component_id x, lithe::entity_id y) {
            get<T>(x, y).~T();
        }


        // Value initialises a region of the buffer.
        template <typename T>
        void zero(lithe::component_id x, lithe::entity_id y) {
            std::fill_n(
                buff + (i + starting->at(x),)  // Find start of component.
                sizeof(T),
                0
            );
        }


        template <typename T>
        void swap_component(
            lithe::component_id x1,
            lithe::entity_id y1,

            lithe::component_id x2,
            lithe::entity_id y2
        ) {
            std::swap(get<T>(x1, y1), get<T>(x2, y2));
        }


        void swap(
            lithe::entity_id a,
            lithe::entity_id b
        );
    };
}


#endif