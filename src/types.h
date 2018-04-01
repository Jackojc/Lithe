#ifndef LITHE_TYPES_H
#define LITHE_TYPES_H


#include <bitset>
#include <memory>
#include <set>
#include <chrono>
#include <cstdint>
#include "constants.h"


namespace lithe {
    // Handy aliases for if we ever need to change the underlying type.
    using component_id = uintmax_t;
    using entity_id = uintmax_t;

    using component_ids = std::set<component_id>;
    using entity_ids = std::set<entity_id>;

    // Type alias to make things perhaps a little more clear.
    using buffer = std::shared_ptr<char>;

    // Function pointer aliases for handling creation
    // and cleanup of underlying memory for the engine.
    using handler_create  = char*(*)(size_t, lithe::entity_id);
    using handler_destroy = void(*) (char*);

    // Type alias for generic function pointer,
    // looks nicer than the standard syntax.
    template <typename T, typename... Ts>
    using fn_ptr = T(*)(Ts...);


    // Used for keeping track of living or dead components.
    using bitmask = std::bitset<LITHE_DEFAULT_COMPONENT_NUM>;


    // Chrono aliases.
    using nano  = std::chrono::nanoseconds;
    using micro = std::chrono::microseconds;
    using milli = std::chrono::milliseconds;
    using sec   = std::chrono::seconds;
    using min   = std::chrono::minutes;
    using hour  = std::chrono::hours;
}


#endif