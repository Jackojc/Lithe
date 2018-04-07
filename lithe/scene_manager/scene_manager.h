#ifndef LITHE_SCENE_MANAGER_H
#define LITHE_SCENE_MANAGER_H


#include <utility>
#include <cstddef>
#include <type_traits>
#include "../constants.h"
#include "../scene/scene.h"
#include "../stack/stack.h"


namespace lithe {
    // Max number of scenes (S).
    template <size_t S>
    struct scene_manager_base {
        lithe::stack<std::unique_ptr<lithe::scene>, S> scenes;


        // Get the current scene.
        lithe::scene& get() {
            return *scenes.top();
        }


        // Add a scene to the stack and pause the one
        // that is already there.
        template <typename T, typename... Ts>
        void attach(Ts&&... ts) {
            LITHE_STATIC_ASSERT(
                (std::is_base_of<lithe::scene, T>::value),
                "T must be derived from `lithe::scene`."
            );

            if (!scenes.empty())
                get().pause();

            scenes.push(std::make_unique<T>(std::forward<Ts>(ts)...));
        }


        // Remove a scene object and resume the one below it.
        void detach() {
            // Free the underlying object held by unique_ptr.
            scenes.top().reset();
            scenes.pop();

            if (!scenes.empty())
                get().resume();
        }


        // Update the current scene.
        void update() {
            if (!scenes.empty())
                get().update_all();
        }
    };


    using scene_manager = scene_manager_base<LITHE_DEFAULT_SCENE_NUM>;
}


#endif