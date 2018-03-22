#ifndef LITHE_SCENE_MANAGER_H
#define LITHE_SCENE_MANAGER_H


#include <cstddef>
#include <stack>
#include <type_traits>
#include "../scene/scene.h"


namespace lithe {
    struct scene_manager {
        std::stack<lithe::scene*> objs;


        ~scene_manager();


        // Add a scene to the stack and pause the one
        // that is already there.
        template <typename T>
        void add(T scn) {
            static_assert(
                std::is_base_of<lithe::scene, T>(),
                "T must be derived from scene"
            );

            if (!objs.empty())
                current().pause();

            objs.push(new T(scn));
        }


        void remove();


        lithe::scene& current() const;


        void update();
    };
}


#endif