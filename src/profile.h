#ifndef LITHE_PROFILE_H
#define LITHE_PROFILE_H


#include <chrono>
#include "types.h"


namespace lithe {
    // Generic function to profile performance of a function.
    template <
        typename Tunit = std::chrono::seconds,
        typename Tfunc,
        typename... Ts
    >
    double profile(Tfunc func, Ts&&... args) {
        // Take a reading before the function is run.
        auto start = std::chrono::high_resolution_clock::now();

        // Run the function and forward the arguments.
        func(std::forward<Ts>(args)...);

        // And a reading after it has run.
        auto end = std::chrono::high_resolution_clock::now();

        // Return the time taken for the function to run
        // and cast it to a double.
        return std::chrono::duration_cast<Tunit>(end - start).count();
    }
}


#endif