#ifndef LITHE_ASSERT_H
#define LITHE_ASSERT_H


#include <stdexcept>
#include "constants.h"


namespace lithe {
    #define LITHE_STATIC_ASSERT(cond, msg) \
        static_assert(cond, msg);


    #ifdef LITHE_DEBUG_FLAG
        #define LITHE_ASSERT(cond, msg) \
            if (!(cond)) { \
                throw std::runtime_error(msg); \
            }

    #else
        #define LITHE_ASSERT(cond, msg) \
            ((void*)0);
    #endif
}


#endif