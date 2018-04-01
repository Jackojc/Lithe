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











struct update_positions:
    lithe::system,
    lithe::system_tag<position, name>
{
    void update(lithe::entity&& entity) override {
        lithe::metadata& meta = entity.get<lithe::metadata>();

        if (lithe::compare_bitmasks(meta.tag, tag))
            std::cout << "MATCH: " << entity.uid << std::endl;
    }
};









const int NUM_ENTITIES = 100;
lithe::component_group<position, name> COMPONENTS;



int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info(
        COMPONENTS,
        NUM_ENTITIES
    );

    auto& buffer    = lithe::setup_buffer(info);
    auto& allocator = lithe::setup_allocator(info);
    auto& container = lithe::setup_container(info);


    // Error checking.
    if (info.buffer == nullptr) {
        std::cerr << "Could not allocate enough memory to process!\n";
        return -1;
    }


    update_positions pos;


    lithe::entity a(0, container);
    lithe::entity b(1, container);


    a.attach(position{2, 1});
    a.attach(name{"A"});


    pos.enroll({0, 1});
    pos.update_entities(container);


    return 0;
}