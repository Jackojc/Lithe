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











namespace lithe {



    template <typename... Ts>
    inline std::vector<lithe::component_id> get_ids() {
        return {lithe::get_type_uid<Ts>()...};
    }


    inline bitmask create_bitmask(
        const std::vector<lithe::component_id>& uids
    ) {
        bitmask bits;

        for (const auto& uid: uids) {
            bits[uid] = true;
        }

        return bits;
    }


    template <typename... Ts>
    struct system_tag {
        lithe::bitmask bits;

        system_tag():
            bits(create_bitmask(get_ids<Ts...>()))
        {

        }
    };


    template <typename T>
    struct system {
        std::set<lithe::entity_id> entities;


        system() {

        }

        virtual ~system() {}


        void update() {
            std::cerr << "Hello from the system side.\n";
            for (const auto& entity: entities)
                static_cast<T*>(this)->update(entity);
        }


        void enroll(lithe::entity_id entity) {
            entities.emplace(entity);
        }


        void enroll(const lithe::entity_ids& ids) {
            entities.insert(ids.begin(), ids.end());
        }


        void expel(lithe::entity_id entity) {
            entities.erase(
                std::remove(entities.begin(), entities.end(), entity),
                entities.end()
            );
        }


        void expel(const lithe::entity_ids& ids) {
            entities.erase(
                std::remove_if(
                    entities.begin(),
                    entities.end(),
                    [&](lithe::entity_id entity){
                        return ids.find(entity) != ids.end();
                    }),
                entities.end()
            );
        }
    };
}


struct update_positions:
    lithe::system<update_positions>,
    lithe::system_tag<position, name>
{
    void update(lithe::entity_id entity) {
        std::cerr << "Hello from the update side: " << entity << "\n";
    }
};









const int NUM_ENTITIES = 100;


int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info<lithe::metadata, position, name>(NUM_ENTITIES);
    auto &buffer    = lithe::setup_buffer(info);
    auto &allocator = lithe::setup_allocator(info);
    auto &container = lithe::setup_container(info);


    // Error checking.
    if (info.buffer == nullptr) {
        std::cerr << "Could not allocate enough memory to process!\n";
        return -1;
    }


    for (float i = 0; i < NUM_ENTITIES; ++i) {
        container.attach(i, position{i, i}, name{"Hello"});
    }


    for (float i = 0; i < NUM_ENTITIES; ++i) {
        if (!container.has<position, name>(i))
            std::cout << "NOPE\n";
    }


    for (float i = 0; i < NUM_ENTITIES; ++i) {
        container.detach<position, name>(i);
    }


    return 0;
}