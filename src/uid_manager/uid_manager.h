#ifndef LITHE_UID_MANAGER_H
#define LITHE_UID_MANAGER_H


#include <cstddef>
#include <vector>
#include "../stack/stack.h"
#include "../types.h"


namespace lithe {
    template <size_t S>
    struct uid_manager_base {
        lithe::entity_id current;
        lithe::stack<lithe::entity_id, S> unused;
        bool any_unused;


        lithe::entity_id withdraw();
        void deposit(lithe::entity_id uid);


        std::vector<lithe::entity_id> withdraw(unsigned num);
        void deposit(std::vector<lithe::entity_id>&& uids);
    };


    using uid_manager = uid_manager_base<2014>;
}


#endif