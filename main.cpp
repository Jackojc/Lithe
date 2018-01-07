#include <iostream>
#include "src/order.h"
#include "src/buffer/buffer.h"
#include "src/allocator/allocator.h"
#include "src/component_container/component_container.h"


// TODO
/*
 - Game state class
 - Game state manager
 - Game object
*/


struct position { float x, y;       };
struct colour   { int   r, g, b, a; };
struct velocity { float x, y, z;    };


int main(int argc, const char* argv[]) {
    // Setup.
    lithe::order_types<position, colour, velocity>();

    auto sizes       = get_sizes<position, colour, velocity>();
    auto chunk_size  = get_total(sizes);
    auto starting    = get_origins(sizes);
    auto buff        = lithe::buffer(chunk_size, 1000000);

    lithe::allocator alloc(buff, sizes, starting);
    lithe::component_container container(alloc);

    // Container manipulation.
    container.insert(0, position{2, 2});
    auto& p = container.get<position>(0);
    std::cout << p.x << ',' << p.y << std::endl;

    return 0;
}

