#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdint>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include "src/lithe.h"






struct velocity: lithe::component<velocity> {
    float x, y;

    velocity(float X, float Y):
        x(X), y(Y)
    {

    }
};


struct position: lithe::component<position> {
    float x, y;

    position(float X, float Y):
        x(X), y(Y)
    {

    }
};


struct name: lithe::component<name> {
    std::string n;

    name(const std::string& N):
        n(N)
    {

    }
};











struct update_positions: lithe::system {
    update_positions(): lithe::system(
        lithe::component_group<position, velocity>{}
    ) {}


    void update(lithe::entity&& entity) override {
        position& p       = entity.get<position>();
        const velocity& v = entity.get<velocity>();

        p.x += v.x;
        p.y += v.y;

        std::cout << "Updated position of " << entity.uid << std::endl;
    }
};


struct print_position_and_name: lithe::system {
    print_position_and_name(): lithe::system(
        lithe::component_group<position, name>{}
    ) {}


    void update(lithe::entity&& entity) override {
        const position& p = entity.get<position>();
        const name& n     = entity.get<name>();

        std::cout
            << "Position of "
            << n.n << ": "
            << p.x << ", " << p.y
        << "\n\n";
    }
};









const int NUM_ENTITIES = 100;
lithe::component_group<velocity, position, name> COMPONENTS;



int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info(
        COMPONENTS,
        NUM_ENTITIES
    );

    auto& buffer    = lithe::setup_buffer(info);
    auto& allocator = lithe::setup_allocator(info);
    auto& container = lithe::setup_container(info);
    auto& uids      = lithe::setup_uid_manager(info);
    auto& world     = lithe::setup_world(info);


    // Error checking.
    if (info.buffer == nullptr) {
        std::cerr << "Could not allocate enough memory to process!\n";
        return -1;
    }


    auto a = world.create_entity();

    world.create_system<update_positions>();
    world.create_system<print_position_and_name>();

    a.attach(position{0, 0});
    a.attach(velocity{5, 5});
    a.attach(name{"A"});

    for (int i = 0; i < 5; ++i)
        world.update();


    return 0;
}