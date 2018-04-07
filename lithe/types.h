#ifndef LITHE_TYPES_H
#define LITHE_TYPES_H


#include <vector>
#include <bitset>
#include <memory>
#include <set>
#include <chrono>
#include <cstdint>
#include <cstddef>
#include "constants.h"


namespace lithe {
    // Info aliases.
    using component_sizes = std::vector<size_t>;
    using component_origins = std::vector<size_t>;
    using component_size = size_t;
    using entity_size = size_t;

    // Store a collection of component types.
    template <typename... Ts>
    struct component_group {};


    // Handy aliases for if we ever need to change the underlying type.
    using component_id = uintmax_t;
    using entity_id = uintmax_t;
    using system_id = uintmax_t;

    using component_ids = std::set<component_id>;
    using entity_ids = std::set<entity_id>;

    // Type alias to make things perhaps a little more clear.
    using buffer_type = char*;
    using buffer = std::unique_ptr<char, void(*)(buffer_type)>;


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