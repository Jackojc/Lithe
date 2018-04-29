#ifndef LITHE_UID_MANAGER_H
#define LITHE_UID_MANAGER_H


#include <stdexcept>
#include <cstddef>
#include <vector>
#include "../constants.h"
#include "../types.h"
#include "../stack/stack.h"


namespace lithe {
    struct uid_manager {
        const lithe::info& info;
        lithe::entity_id current;
        lithe::stack<lithe::entity_id> unused;
        bool any_unused;


        uid_manager(
            const lithe::info& info_,
            size_t size = LITHE_DEFAULT_ENTITY_NUM
        ):
            info(info_),
            current(0),
            unused(size),
            any_unused(false)
        {

        }


        // Withdraw a unique ID.
        lithe::entity_id withdraw() {
            // Check if there are any lower IDs available.
            if (any_unused) {
                if (unused.size() == 1)
                    any_unused = false;

                auto tmp = unused.top();
                unused.pop();
                return tmp;
            }

            if (current + 1 > info.num_entities)
                throw std::runtime_error(
                    "Requested a UID larger than the maximum number of entities."
                );

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
        lithe::entity_ids withdraw(unsigned num) {
            lithe::entity_ids uids;

            for (unsigned i = 0; i < num; ++i) {
                uids.insert(withdraw());
            }

            return uids;
        }


        // Deposit many IDs at once.
        void deposit(const lithe::entity_ids& uids) {
            for (auto uid: uids) {
                deposit(uid);
            }
        }
    };
}


#endif