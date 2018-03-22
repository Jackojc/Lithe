#include "uid_manager.h"


namespace lithe {
    lithe::entity_id uid_manager::withdraw() {
        if (any_unused) {
            if (unused.size() == 1)
                any_unused = false;
            return unused.pop();
        }

        return current++;
    }

    void uid_manager::deposit(lithe::entity_id uid) {
        if (uid - 1 == current) {
            current--;
            return;
        }

        any_unused = true;
        unused.push(uid);
    }


    std::vector<lithe::entity_id> uid_manager::withdraw(unsigned num) {
        std::vector<lithe::entity_id> uids;

        for (unsigned i = 0; i < num; ++i) {
            uids.push_back(withdraw());
        }

        return uids;
    }

    void uid_manager::deposit(std::vector<lithe::entity_id>&& uids) {
        for (auto uid: uids) {
            deposit(uid);
        }
    }
}