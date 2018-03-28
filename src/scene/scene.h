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


        void internal_event();
        void internal_update();
        void internal_draw();

        void update_all();
    };
}


#endif