#include <iostream>
#include <chrono>
#include <cstdint>


#include "src/utils.h"
#include "src/uid.h"
#include "src/order.h"
#include "src/profile.h"
#include "src/allocator/allocator.h"
#include "src/container/container.h"
#include "src/entity/entity.h"



// COMPONENTS
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








// Function that iterates from 0 to ENTITIES and inserts components.
void create_positions(lithe::container& container, unsigned num_entities) {
    for (lithe::entity_id i = 0; i < num_entities; ++i) {
        float tmp = static_cast<float>(i);
        container.insert(i, position{tmp, tmp});
        container.insert(i, name{"Hello"});
    }
}




// Number of entities.
constexpr uintmax_t ENTITIES = 100;


// Aliases for convenience.
using ns = std::chrono::nanoseconds;
using ms = std::chrono::milliseconds;
using sec = std::chrono::seconds;


int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info<position, name>(ENTITIES);
    auto &container = info.get_container();


    // Error checking.
	if (info.buffer == nullptr) {
		std::cerr << "Could not allocate enough memory to process!\n";
		return -1;
	}


    std::cout
        << "Took: "
        << lithe::profile<ms>(&create_positions, container, ENTITIES)
        << "ms"
    << std::endl;


    return 0;
}