#ifndef LITHE_STACK_H
#define LITHE_STACK_H


#include <array>


namespace lithe {
    template <typename T, size_t S>
    struct stack {
        std::array<T, S> items_;
        unsigned index_ = 0;


        void push(const T& value) {
            items_[index_++] = value;
        }


        T pop() {
            return items_[--index_];
        }


        T peek(const unsigned index) const {
            return items_[index];
        }


        T peek() const {
            return items_[index_];
        }


        T peek_top() const {
            return items_[index_];
        }


        void clear() {
            index_ = 0;
        }

        size_t size() const {
            return index_;
        }
    };
}


#endif