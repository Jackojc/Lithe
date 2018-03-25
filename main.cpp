#include <iostream>
#include <chrono>
#include <cstdint>


#include "src/lithe.h"



// COMPONENTS
struct position: lithe::component<position> {
    long unsigned x, y;

    position(long unsigned X, long unsigned Y):
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
        container.insert(i, position{i, i}, name{"Hello"});
    }


    for (lithe::entity_id i = 0; i < num_entities; ++i) {
        container.remove<position>(i);
    }
}




// Number of entities.
constexpr uintmax_t ENTITIES = 5;


// Aliases for convenience.
using ns = std::chrono::nanoseconds;
using ms = std::chrono::milliseconds;
using sec = std::chrono::seconds;


int main(int argc, const char* argv[]) {
    auto info       = lithe::setup_info<position, name>(ENTITIES);
    auto &buffer    = lithe::setup_buffer(info);
    auto &allocator = lithe::setup_allocator(info);
    auto &container = lithe::setup_container(info);


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


    delete buffer;


    return 0;
}