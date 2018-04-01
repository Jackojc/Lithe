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
    unsigned long long x, y;

    position(unsigned long long X, unsigned long long Y):
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












int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info<position, name>(100);
    auto &buffer    = lithe::setup_buffer(info);
    auto &allocator = lithe::setup_allocator(info);
    auto &container = lithe::setup_container(info);


    // Error checking.
    if (info.buffer == nullptr) {
        std::cerr << "Could not allocate enough memory to process!\n";
        return -1;
    }


    update_positions pos;

    lithe::entity a(0, container);
    lithe::entity b(1, container);




    return 0;
}