#include <iostream>
#include "src/scene_manager/scene_manager.h"


struct main_menu: lithe::scene {
    void resume() override {
        std::cout << "Resumed menu.\n";
    }


    void pause() override {
        std::cout << "Paused menu.\n";
    }


    void update() override {
        std::cout << "Update menu.\n";
    }
};


int main(int argc, const char* argv[]) {
    lithe::scene_manager manager;

    main_menu menu;
    manager.add(menu);

    for (int i = 0; i < 5; ++i)
        manager.update();

    return 0;
}