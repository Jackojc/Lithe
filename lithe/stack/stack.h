#ifndef LITHE_STACK_H
#define LITHE_STACK_H


#include <vector>
#include "../constants.h"


namespace lithe {
    template <typename T>
    struct stack {
        std::vector<T> items;


        stack() {
            items.reserve(LITHE_DEFAULT_STACK_SIZE);
        }


        stack(size_t size) {
            items.reserve(size);
        }


        // Push an object to the stack.
        void push(const T& value) {
            items.emplace_back(value);
        }


        void push(T&& value) {
            items.emplace_back(std::move(value));
        }


        // Pop an object from the stack.
        void pop() {
            items.pop_back();
        }


        // Peek at any index in the stack.
        T& peek(const unsigned index) {
            return items.at(index);
        }


        // Peek the top index of the stack.
        T& top() {
            return items.back();
        }


        // Invalidate all items in the stack.
        void clear() {
            items.clear();
        }


        // Get the numbers of items in the stack.
        size_t size() const {
            return items.size();
        }


        // Check whether stack is empty or not.
        bool empty() const {
            return items.empty();
        }
    };
}


#endif