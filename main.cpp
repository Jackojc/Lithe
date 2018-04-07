#include <iostream>
#include "lithe/lithe.h"








// COMPONENTS
struct velocity: lithe::component {
    float x, y;
    velocity(float X, float Y): x(X), y(Y) {}
};


struct position: lithe::component {
    float x, y;
    position(float X, float Y): x(X), y(Y) {}
};


struct name: lithe::component {
    std::string n;
    name(const std::string& N): n(N) {}
};










// SYSTEMS
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














// CONSTANTS
auto NUM_ENTITIES = 2;
auto COMPONENTS = lithe::component_group<name, velocity, position>{};













int main(int argc, const char* argv[]) {
    auto info = lithe::info(
        NUM_ENTITIES,
        COMPONENTS,
        lithe::get_implicit_components()
    );


    auto buffer    = lithe::create_buffer(info);
    auto core      = lithe::create_core(buffer, info);
    auto world     = lithe::create_world(core);


    // Error checking.
    if (buffer == nullptr) {
        std::cerr << "Could not allocate enough memory to process!\n";
        return -1;
    }


    // Setup systems to use.
    world.attach<update_positions>();
    world.attach<print_position_and_name>();


    // Create an entity and attach components.
    auto a = world.create();
    auto b = world.create();


    a.attach(position{0, 0});
    a.attach(velocity{2, 2});
    a.attach(name{"Batman"});

    b.attach(name{"Joker"});
    b.attach(position{45, 45});


    a.swap<name, position>(b);


    // Update the world a few times.
    for (int i = 0; i < 3; ++i) {
        world.update();
    }


    return 0;
}