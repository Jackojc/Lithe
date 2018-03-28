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


        // Withdraw a unique ID.
        lithe::entity_id withdraw() {
            // Check if there are any lower IDs available.
            if (any_unused) {
                if (unused.size() == 1)
                    any_unused = false;
                return unused.pop();
            }

            // If not, lets make a new ID.
            return current++;
        }


        // Give back a unique ID to be recycled.
        void deposit(lithe::entity_id uid) {
            // If this was the last ID to be withdrawn,
            // we can decrement the max ID.
            if (uid - 1 == current) {
                current--;
                return;
            }

            any_unused = true;
            unused.push(uid);
        }


        // Withdraw many IDs at once.
        std::vector<lithe::entity_id> withdraw(unsigned num) {
            std::vector<lithe::entity_id> uids;

            for (unsigned i = 0; i < num; ++i) {
                uids.push_back(withdraw());
            }

            return uids;
        }


        // Deposit many IDs at once.
        void deposit(std::vector<lithe::entity_id>&& uids) {
            for (auto uid: uids) {
                deposit(uid);
            }
        }
    };


    using uid_manager = uid_manager_base<2014>;
}


#endif