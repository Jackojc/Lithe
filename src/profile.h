#ifndef LITHE_PROFILE_H
#define LITHE_PROFILE_H


#include <chrono>
#include "types.h"


namespace lithe {
    // Generic function to profile performance of a function.
    template <
        typename unit = std::chrono::seconds,
        typename T,
        typename... TArgs,
        typename... TArgs2
    >
    double profile(lithe::fn_ptr<T, TArgs...> func, TArgs2&&... args) {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<TArgs2>(args)...);
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<unit>(end - start).count();
    }
}


#endif