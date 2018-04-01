#ifndef LITHE_WORLD_H
#define LITHE_WORLD_H


#include <set>
#include <list>
#include <algorithm>
#include "../types.h"
#include "../bitmask.h"
#include "../system/system.h"
#include "../entity/entity.h"
#include "../allocator/allocator.h"
#include "../container/container.h"
#include "../uid_manager/uid_manager.h"


namespace lithe {
    struct world {
        lithe::container* container;
        lithe::uid_manager* uids;

        std::list<lithe::system*> systems;
        lithe::entity_ids entities;


        world(
            lithe::container* container_,
            lithe::uid_manager* uids_
        );


        template <typename T>
        lithe::system* create_system() {
            systems.push_back(new T());
            return systems.back();
        }


        void delete_system(lithe::system* sys);

        lithe::entity create_entity();
        void delete_entity(const lithe::entity& entity);

        void update();
    };
}


#endif