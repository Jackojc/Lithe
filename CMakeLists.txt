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


file(GLOB_RECURSE ENTITY
    "src/entity/*.cpp"
)


file(GLOB_RECURSE SCENE_MANAGER
    "src/scene_manager/*.cpp"
)


file(GLOB_RECURSE SCENE
    "src/scene/*.cpp"
)


file(GLOB_RECURSE MISC
    "src/*.cpp"
    "src/*.h"
)


# EXECUTABLE
add_executable(${PROJECT_NAME} ${BUFFER} ${ALLOCATOR} ${COMPONENT_CONTAINER} ${ENTITY} ${SCENE_MANAGER} ${SCENE} ${MISC} ${MAIN})


# FILTERS
source_group("buffer" FILES ${BUFFER})
source_group("allocator" FILES ${ALLOCATOR})
source_group("component_container" FILES ${COMPONENT_CONTAINER})
source_group("entity" FILES ${ENTITY})
source_group("scene_manager" FILES ${SCENE_MANAGER})
source_group("scene" FILES ${SCENE})
source_group("misc" FILES ${MISC})


# LINK
#target_link_libraries(${PROJECT_NAME})


# GCC
if(CMAKE_COMPILER_IS_GNUCXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Ofast -flto -m64")
endif(CMAKE_COMPILER_IS_GNUCXX)

#MSVC
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3 /Ox /GL")
endif(MSVC)


# PROPERTIES
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
