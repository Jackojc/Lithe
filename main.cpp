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








constexpr unsigned ENTITIES = 10;





int main(int argc, const char* argv[]) {
    auto info      = lithe::get_info<position, name>();
    auto buff      = lithe::setup_buffer(info, ENTITIES);
    auto alloc     = lithe::setup_allocator(info, buff);
    auto container = lithe::setup_container(alloc);


    lithe::entity a(0, container);
    lithe::entity b(1, container);


    a.insert(position{3, 3});
    a.insert(name{"A"});


    b.insert(position{77, 77});
    b.insert(name{"B"});


    a.get<position>().print();
    a.get<name>().print();
    b.get<position>().print();
    b.get<name>().print();


    std::cout << "SWAP\n";
    a.swap(b.uid);


    a.get<position>().print();
    a.get<name>().print();
    b.get<position>().print();
    b.get<name>().print();





    return 0;
}