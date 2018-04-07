#ifndef LITHE_SCENE_H
#define LITHE_SCENE_H


namespace lithe {
    struct scene {
        // Virtual functions that are to be
        // implemented by the user.
        virtual ~scene() {}

        virtual void event() {}
        virtual void update() {}
        virtual void draw() {}

        virtual void pause() {}
        virtual void resume() {}


        // These functions wrap the call to the virtual functions
        // implemented by the user.
        // Handy if you want to add logging or something.
        void internal_event() {
            event();
        }


        void internal_update() {
            update();
        }


        void internal_draw() {
            draw();
        }


        // Calls all the wrapper functions and in turn
        // the functions the user has implemented.
        void update_all() {
            internal_event();
            internal_update();
            internal_draw();
        }
    };
}


#endif