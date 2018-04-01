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
        std::vector<size_t>* origins;
        size_t entity_size;


        // These arrays must be passed by value or else
        // we get a segmentation fault for trying to
        // access variables that have since gone out of
        // scope.
        allocator(
            lithe::buffer buff_,
            std::vector<size_t>* sizes_,
            std::vector<size_t>* origins_,
            size_t entity_size_
        );


        // Insert an object to a buffer.
        template <typename T>
        void attach(lithe::component_id x, lithe::entity_id y, const T& item) {
            size_t i = lithe::translate_index(entity_size, x, y);

            new (buff.get() + (i + origins->at(x))) T(item);
        }


        // Get an object by reference from the buffer.
        // This function allows you to get the object
        // - both by val and by ref.
        // e.g: auto& (ref) or auto (val).
        template <typename T>
        T& get(lithe::component_id x, lithe::entity_id y) const {
            size_t i = lithe::translate_index(entity_size, x, y);

            return *static_cast<T*>(
                static_cast<void*>(buff.get() + (i + origins->at(x)))
            );
        }


        // Calls destructor on component.
        template <typename T>
        void detach(lithe::component_id x, lithe::entity_id y) {
            get<T>(x, y).~T();
        }


        // Value initialises a region of the buffer.
        template <typename T>
        void zero(lithe::component_id x, lithe::entity_id y) {
            size_t i = lithe::translate_index(entity_size, x, y);

            std::fill_n(
                buff.get() + (i + origins->at(x)),  // Find start of component.
                sizeof(T),
                char{0}
            );
        }


        // Swap a single component between two entities.
        template <typename T>
        void swap_component(
            lithe::component_id x1,
            lithe::entity_id y1,

            lithe::component_id x2,
            lithe::entity_id y2
        ) {
            std::swap(get<T>(x1, y1), get<T>(x2, y2));
        }


        // Swap two entities. (and their components.)
        void swap(
            lithe::entity_id a,
            lithe::entity_id b
        );
    };
}


#endif