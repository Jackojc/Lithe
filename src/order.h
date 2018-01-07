#ifndef LITHE_ORDER_H
#define LITHE_ORDER_H


#include "uid.h"


namespace lithe {
    // Calling this function will in turn call get_type_id().
    // However, take note that it will call it in the same
    // order of the types in the variadic template.
    template <typename T>
    void order_types() {
        get_type_id<T>();
    }


    // This function calls itself recursively because
    // templates. >_>
    template <typename T, typename T2, typename... TArgs>
    void order_types() {
        get_type_id<T>();
        order_types<T2, TArgs...>();
    }
}


#endif