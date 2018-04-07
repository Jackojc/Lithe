#ifndef LITHE_CONTAINER_H
#define LITHE_CONTAINER_H


#include "../constants.h"
#include "../assert.h"
#include "../types.h"
#include "../uid.h"
#include "../translate_index.h"
#include "../allocator/allocator.h"
#include "../component/component.h"
#include "../component/defaults.h"


namespace lithe {
    // Component interface.
    struct container: lithe::allocator {
        container(
            lithe::buffer& buff_,
            const lithe::info& info_
        ):
            lithe::allocator(buff_, info_)
        {

        }


        // Returns a reference to a component within an entity.
        template <typename T>
        T& get(lithe::entity_id entity) const {
            return lithe::allocator::get<T>(
                lithe::get_component_uid<T>(),
                entity
            );
        }


        // Check whether or not a component is attached.
        template <typename T>
        bool has(lithe::entity_id entity) const {
            return get<lithe::metadata>(entity).tag[
                lithe::get_component_uid<T>()
            ];
        }


        // Check for existence of multiple components.
        template<typename T1, typename T2, typename... Ts>
        bool has(lithe::entity_id entity) {
            if (!has<T1>(entity))
                return false;
            return has<T2, Ts...>(entity);
        }


        // Attaches a component to a specified entity.
        template <typename T>
        void attach(lithe::entity_id entity, const T& item) {
            LITHE_STATIC_ASSERT(
                (std::is_base_of<lithe::component, T>::value),
                "T must be derived from `lithe::component`."
            );

            lithe::allocator::attach(
                lithe::get_component_uid<T>(),
                entity,
                item
            );

            get<lithe::metadata>(entity).tag[
                lithe::get_component_uid<T>()
            ] = true;
        }


        // Convenience wrapper to allow you to remove
        // multiple components with one call.
        template<typename T1, typename T2, typename... Ts>
        void attach(lithe::entity_id entity, const T1& t, const Ts&&... ts) {
            attach(entity, t);
            attach<T2, Ts...>(entity, ts...);
        }


        // Detaches a component from an entity.
        template <typename T>
        void detach(lithe::entity_id entity) {
            get<lithe::metadata>(entity).tag[
                lithe::get_component_uid<T>()
            ] = false;

            detach<T>(lithe::get_component_uid<T>(), entity);
            zero<T>(lithe::get_component_uid<T>(), entity);
        }


        // Convenience wrapper to detach multiple
        // components with a single call.
        template <typename T1, typename T2, typename... Ts>
        void detach(lithe::entity_id entity) {
            detach<T1>(entity);
            detach<T2, Ts...>(entity);
        }


        // Swap a single component between two entities.
        template <typename T>
        void swap_component(lithe::entity_id a, lithe::entity_id b) {
            lithe::component_id tmp = lithe::get_component_uid<T>();
            lithe::allocator::swap_component<T>(tmp, a, tmp, b);
        }


        // Swap two entities. (and their components.)
        void swap(lithe::entity_id a, lithe::entity_id b) {
            lithe::allocator::swap(a, b);
        }
    };
}


#endif