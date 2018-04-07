#ifndef LITHE_ALLOCATOR_H
#define LITHE_ALLOCATOR_H


#include <cstddef>
#include <new>
#include <algorithm>
#include "../types.h"
#include "../translate_index.h"
#include "../info/info.h"


namespace lithe {
    // Allocates and manipulates a
    // buffer of objects.
    struct allocator {
        const lithe::buffer& buff;
        const lithe::info& info;


        // These arrays must be passed by value or else
        // we get a segmentation fault for trying to
        // access variables that have since gone out of
        // scope.
        allocator(
            const lithe::buffer& buff_,
            const lithe::info& info_
        ):
            buff(buff_),
            info(info_)
        {

        }


        // Insert an object to a buffer.
        template <typename T>
        void attach(lithe::component_id x, lithe::entity_id y, const T& item) {
            new (lithe::translate_index(buff, info, x, y)) T(item);
        }


        // Get an object by reference from the buffer.
        // This function allows you to get the object
        // - both by val and by ref.
        // e.g: auto& (ref) or auto (val).
        template <typename T>
        T& get(lithe::component_id x, lithe::entity_id y) const {
            return *static_cast<T*>(
                static_cast<void*>(lithe::translate_index(buff, info, x, y))
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
            std::fill_n(
                // Find start of component.
                lithe::translate_index(buff, info, x, y),
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
        ) {
            std::swap_ranges(
                buff.get() + (info.entity_size * a),
                buff.get() + (info.entity_size * a) + info.entity_size,
                buff.get() + (info.entity_size * b)
            );
        }
    };
}


#endif