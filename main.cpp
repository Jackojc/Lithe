#include <iostream>
#include <vector>
#include <deque>

#include "src/utils.h"
#include "src/uid.h"
#include "src/order.h"
#include "src/allocator/allocator.h"
#include "src/container/container.h"
#include "src/entity/entity.h"


// COMPONENTS
struct position {
    float x, y;

    void print() {
        std::cout << x << ": " << y << std::endl;
    }
};


struct name {
    std::string n;

    void print() {
        std::cout << n << std::endl;
    }
};



// SYSTEMS
void update_position(lithe::entity& self, float x, float y) {
    auto& pos = self.get<position>();

    pos.x += x;
    pos.y += y;
}





















/*struct world {
    // holds systems, entities and components...

    void new_system(system sys);
    void rem_system();

    void update();

    Entity& new_entity();
    void rem_entity(entity&);
    void get_entity(int id);
};
*/








constexpr unsigned ENTITIES = 100000000;





int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info<position, name>(ENTITIES);
    auto &container = info.get_container();


	if (info.buffer == nullptr) {
		std::cerr << "Could not allocate enough memory to process!\n";
		return -1;
	}


    for (lithe::entity_id i = 0; i < ENTITIES; ++i) {
        float tmp = static_cast<float>(i);
        container.insert(i, position{ tmp, tmp });
    }


    /*for (lithe::entity_id i = 0; i < ENTITIES; ++i) {
        position& p = container.get<position>(i);

        p.x += 0.1f;
        p.y += 0.1f;
    }*/


    return 0;
}