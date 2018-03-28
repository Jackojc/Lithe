#ifndef LITHE_ASSERT_H
#define LITHE_ASSERT_H


#include <stdexcept>
#include "constants.h"


namespace lithe {
    // Compile time assertion.
    #define LITHE_STATIC_ASSERT(cond, msg) \
        static_assert(cond, msg);


    // Runtime assertion.
    #ifdef LITHE_DEBUG_FLAG
        #define LITHE_ASSERT(cond, msg) \
            if (!(cond)) { \
                throw std::runtime_error(msg); \
            }

    #else
        // If debug is disabled, avoid runtime overhead.
        #define LITHE_ASSERT(cond, msg) \
            ((void*)0);
    #endif
}


#endif