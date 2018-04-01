#ifndef LITHE_ORDER_H
#define LITHE_ORDER_H


#include "uid.h"


namespace lithe {
    template <typename T>
    void order_types() {
        lithe::get_type_uid<T>();
    }


    template <typename T1, typename T2, typename... Ts>
    void order_types() {
        lithe::get_type_uid<T1>();
        order_types<T2, Ts...>();
    }
}


#endif