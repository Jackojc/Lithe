#ifndef LITHE_ORDER_H
#define LITHE_ORDER_H


#include "uid.h"


namespace lithe {
    // Calling this function will in turn call lithe::get_type_uid().
    // However, take note that it will call it in the same
    // order of the types in the variadic template.
    template <typename T>
    inline void order_types() {
        lithe::get_type_uid<T>();
    }


    // This function calls itself recursively because
    // templates. >_>
    template <typename T, typename T2, typename... TArgs>
    inline void order_types() {
        lithe::get_type_uid<T>();
        order_types<T2, TArgs...>();
    }
}


#endif