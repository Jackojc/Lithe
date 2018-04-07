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


        void push(T&& value) {
            items_[index_++] = std::move(value);
        }


        // Pop an object from the stack.
        void pop() {
            items_[--index_];
        }


        // Peek at any index in the stack.
        T& peek(const unsigned index) {
            return items_[index];
        }


        // Peek the top index of the stack.
        T& top() {
            return items_[index_ - 1];
        }


        // Invalidate all items in the stack.
        void clear() {
            index_ = 0;
        }


        // Get the numbers of items in the stack.
        size_t size() const {
            return index_;
        }


        // Check whether stack is empty or not.
        bool empty() const {
            return size() == 0;
        }
    };
}


#endif