cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME lithe)
project(${PROJECT_NAME})


# SOURCE FILES
set(MAIN main.cpp)


file(GLOB_RECURSE BUFFER
    "src/buffer/*.cpp"
)


file(GLOB_RECURSE ALLOCATOR
    "src/allocator/*.cpp"
)


file(GLOB_RECURSE COMPONENT_CONTAINER
    "src/component_container/*.cpp"
)


file(GLOB_RECURSE MISC
    "src/*.cpp"
    "src/*.h"
)


# EXECUTABLE
add_executable(${PROJECT_NAME} ${BUFFER} ${ALLOCATOR} ${COMPONENT_CONTAINER} ${MISC} ${MAIN})


# FILTERS
source_group("buffer" FILES ${BUFFER})
source_group("allocator" FILES ${ALLOCATOR})
source_group("component_container" FILES ${COMPONENT_CONTAINER})
source_group("misc" FILES ${MISC})


# LINK
#target_link_libraries(${PROJECT_NAME})


# GCC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Ofast -flto -m64")


# PROPERTIES
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
