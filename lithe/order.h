#ifndef LITHE_ORDER_H
#define LITHE_ORDER_H


#include "uid.h"


namespace lithe {
    // Just a wrapper to help template recursion.
    template <typename T>
    void order_types() {
        lithe::get_component_uid<T>();
    }


    // Assign IDs to multiple components.
    template <typename T1, typename T2, typename... Ts>
    void order_types() {
        lithe::get_component_uid<T1>();
        order_types<T2, Ts...>();
    }
}


#endif