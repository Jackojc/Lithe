#ifndef LITHE_STACK_H
#define LITHE_STACK_H


#include <array>
#include "../constants.h"


namespace lithe {
    template <typename T, size_t S = LITHE_DEFAULT_STACK_SIZE>
    struct stack {
        std::array<T, S> items_;
        unsigned index_ = 0;


        // Push an object to the stack.
        void push(const T& value) {
            items_[index_++] = value;
        }


        // Pop an object from the stack.
        T pop() {
            return items_[--index_];
        }


        // Peek at any index in the stack.
        T peek(const unsigned index) const {
            return items_[index];
        }


        // Peek the top index of the stack.
        T peek() const {
            return items_[index_];
        }


        // Invalidate all items in the stack.
        void clear() {
            index_ = 0;
        }


        // Get the numbers of items in the stack.
        size_t size() const {
            return index_;
        }
    };
}


#endif