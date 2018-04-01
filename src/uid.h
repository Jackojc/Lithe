#ifndef LITHE_UID_H
#define LITHE_UID_H


#include <vector>
#include <cstdint>
#include <type_traits>
#include "types.h"


namespace lithe {
    // Generates a new id with each successive call.
    inline lithe::component_id generate_uid() {
        static lithe::component_id uid = 0;
        return uid++;
    };


    // - Since this is a templated function, it generates
    // a new function for every type it is called with.
    // - This means that if you call this function with
    // the same type more than once, it will still
    // return the same ID.
    // - The first time it is called, it gets an ID from
    // generate_uid() and then keeps that ID from there
    // on, hence the use of static below.
    template <typename T>
    lithe::component_id get_type_uid_t() {
        static lithe::component_id get_type_uid = generate_uid();
        return get_type_uid;
    }


    // Get the decayed type of T, "T&&"" becomes T and
    // "const T" becomes T. etc.
    template <typename T>
    lithe::component_id get_type_uid() {
        return get_type_uid_t<std::decay<T>>();
    }


    // Return a container of uids.
    template <typename... Ts>
    inline std::vector<lithe::component_id> get_type_uids() {
        return {lithe::get_type_uid<Ts>()...};
    }
}


#endif