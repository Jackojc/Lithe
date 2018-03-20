#include <iostream>
#include <vector>
#include <deque>

#include "src/utils.h"
#include "src/uid.h"
#include "src/order.h"
#include "src/buffer/buffer.h"
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








constexpr unsigned ENTITIES = 1000;





int main(int argc, const char* argv[]) {
    auto info      = lithe::get_info<position>();
    auto buff      = lithe::setup_buffer(info, ENTITIES);
    auto alloc     = lithe::setup_allocator(info, buff);
    auto container = lithe::setup_container(alloc);

    lithe::entity ent1(0, container);
    lithe::entity ent2(1, container);

    ent1.insert(position{33, 33});
    ent2.insert(position{55, 55});

    ent1.get<position>().print();
    ent2.get<position>().print();

    container.swap<position>(0, 1);

    ent1.get<position>().print();
    ent2.get<position>().print();


    return 0;
}