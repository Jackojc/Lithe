#ifndef LITHE_SYSTEM_H
#define LITHE_SYSTEM_H


#include "../types.h"
#include "../bitmask.h"
#include "../entity/entity.h"
#include "../container/container.h"


namespace lithe {
    struct system_base {
        // Tag used to identify which components a system accepts.
        const lithe::bitmask tag;


        // Constructor that initialises a tag.
        system_base(const lithe::bitmask& tag_):
            tag(tag_)
        {

        }


        virtual ~system_base() {}

        // Member function that is
        // overridden by the user.
        virtual void update(lithe::entity&& entity) = 0;
    };


    template <typename... Ts>
    struct system: lithe::system_base {
        // Assign a tag to the system
        // so we know what components
        // it operates on.
        system():
            lithe::system_base(
                lithe::create_bitmask(lithe::get_component_uids<Ts...>())
            )
        {

        }


        virtual ~system() {}
    };
}


#endif