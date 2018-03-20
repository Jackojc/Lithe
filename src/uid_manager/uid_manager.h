#ifndef LITHE_UID_MANAGER_H
#define LITHE_UID_MANAGER_H


#include <vector>
#include "../stack/stack.h"
#include "../types.h"


namespace lithe {
    struct uid_manager {
        lithe::component_id current;
        lithe::stack<lithe::component_id, 1024> unused;
        bool any_unused;


        lithe::component_id withdraw();
        void deposit(lithe::component_id uid);


        std::vector<lithe::component_id> withdraw(unsigned num);
        void deposit(std::vector<lithe::component_id>&& uids);
    };
}


#endif