#ifndef LITHE_SYSTEM_MANAGER_H
#define LITHE_SYSTEM_MANAGER_H


#include <array>
#include <vector>
#include <bitset>
#include <memory>
#include <utility>
#include "../constants.h"
#include "../assert.h"
#include "../types.h"
#include "../uid.h"
#include "../system/system.h"
#include "../component/defaults.h"


namespace lithe {
    struct system_manager {
        std::array<
            std::unique_ptr<lithe::system>,
            LITHE_DEFAULT_SYSTEM_NUM
        > systems;

        std::bitset<LITHE_DEFAULT_SYSTEM_NUM> bits;


        // Attach a system to the manager
        // and mark it's bit as active.
        template <typename T, typename... Ts>
        void attach(Ts&&... ts) {
            auto ptr = std::make_unique<T>(
                std::forward<Ts>(ts)...
            );

            systems[lithe::get_system_uid<T>()] = std::move(ptr);
            bits[lithe::get_system_uid<T>()] = true;
        }


        // Detach a system from the manager.
        template <typename T>
        void detach() {
            bits[lithe::get_system_uid<T>()] = false;
            systems[lithe::get_system_uid<T>()] = nullptr;
        }


        // Get a reference to a system.
        template <typename T>
        T& get() const {
            return *dynamic_cast<T*>(systems[lithe::get_system_uid<T>()]);
        }


        // Check if the manager has a system.
        template <typename T>
        bool has() const {
            return bits[lithe::get_system_uid<T>()];
        }


        // Update all entities and systems.
        void update_systems(
            const lithe::entity_ids& entities,
            lithe::container& container
        ) {
            std::vector<lithe::system*> active_systems;

            // We just want an array of active systems.
            for (int i = 0; i < LITHE_DEFAULT_SYSTEM_NUM; ++i) {
                if (bits[i])
                    active_systems.emplace_back(systems[i].get());
            }

            // Loop through all entities.
            for (const auto& entity: entities) {
                // Get their metadata.
                const lithe::metadata& meta
                    = container.get<lithe::metadata>(entity);

                // Update a system while passing in an entity
                // ONLY if the mask of the entity and system match.
                for (const auto& sys: active_systems) {
                    if (lithe::compare_bitmasks(meta.tag, sys->tag))
                        sys->update(lithe::entity{entity, container});
                }
            }
        }
    };
}


#endif
