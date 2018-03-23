#ifndef LITHE_TYPES_H
#define LITHE_TYPES_H


#include <cstdint>


namespace lithe {
    using component_id = uintmax_t;
    using entity_id = uintmax_t;

    using buffer = char*;

    // Function pointer aliases for handling creation
    // and cleanup of underlying memory for the engine.
    using handler_create  = char*(*)(size_t, lithe::entity_id);
    using handler_destroy = void(*) (char*);

    // Type alias for generic function pointer,
    // looks nicer than the standard syntax.
    template <typename T, typename... TArgs>
    using fn_ptr = T(*)(TArgs...);
}


#endif