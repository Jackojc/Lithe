#ifndef LITHE_SYSTEM_H
#define LITHE_SYSTEM_H


#include <set>

#include "../types.h"
#include "../entity/entity.h"
#include "../container/container.h"


namespace lithe {
    struct system {
        std::set<lithe::entity_id> entities;


        system() {

        }

        virtual ~system() {}


        virtual void update(lithe::entity&& entity) = 0;


        void update_entities(lithe::container& container) {
            for (auto& entity: entities) {
                update(lithe::entity{entity, container});
            }
        }


        void enroll(lithe::entity_id entity) {
            entities.emplace(entity);
        }


        void enroll(const lithe::entity_ids& ids) {
            entities.insert(ids.begin(), ids.end());
        }


        void expel(lithe::entity_id entity) {
            entities.erase(entity);
        }


        void expel(const lithe::entity_ids& ids) {
            for(auto iter = entities.begin(); iter != entities.end();) {
               if (ids.find(*iter) != ids.end())
                  iter = entities.erase(iter);

               else
                  ++iter;
            }
        }
    };
}


#endif