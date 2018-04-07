#ifndef LITHE_UID_H
#define LITHE_UID_H


#include <vector>
#include <cstdint>
#include <type_traits>
#include "types.h"


namespace lithe {
    // Generates a new id with each successive call.
    inline lithe::component_id generate_component_uid() {
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
    lithe::component_id get_component_uid_base() {
        static lithe::component_id uid = generate_component_uid();
        return uid;
    }


    // Get the decayed type of T, "T&&"" becomes T and
    // "const T" becomes T. etc.
    template <typename T>
    lithe::component_id get_component_uid() {
        return get_component_uid_base<std::decay<T>>();
    }


    // Return a container of uids.
    template <typename... Ts>
    inline std::vector<lithe::component_id> get_component_uids() {
        return {lithe::get_component_uid<Ts>()...};
    }














    // The same functions but for systems.
    inline lithe::system_id generate_system_uid() {
        static lithe::system_id uid = 0;
        return uid++;
    };


    template <typename T>
    lithe::system_id get_system_uid_base() {
        static lithe::system_id uid = generate_system_uid();
        return uid;
    }


    template <typename T>
    lithe::system_id get_system_uid() {
        return get_system_uid_base<std::decay<T>>();
    }


    template <typename... Ts>
    inline std::vector<lithe::system_id> get_system_uids() {
        return {lithe::get_system_uid<Ts>()...};
    }
}


#endif