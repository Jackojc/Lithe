#ifndef LITHE_UID_H
#define LITHE_UID_H


#include <cstdint>


namespace lithe {
    inline uintmax_t get_entity_uid() {
        static uintmax_t uid = 0;
        return uid++;
    };


    // Generates a new id with each successive call.
    inline uintmax_t generate_uid() {
        static uintmax_t uid = 0;
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
    uintmax_t get_type_uid() {
        static uintmax_t get_type_uid = generate_uid();
        return get_type_uid;
    }
}


#endif