cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME lithe)
project(${PROJECT_NAME})


# SOURCE FILES
set(MAIN main.cpp)


file(GLOB_RECURSE ALLOCATOR
    "src/allocator/*.cpp"
)


file(GLOB_RECURSE CONTAINER
    "src/container/*.cpp"
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


file(GLOB_RECURSE UID_MANAGER
    "src/uid_manager/*.cpp"
)


file(GLOB_RECURSE INFO
    "src/info/*.cpp"
)


file(GLOB_RECURSE MISC
    "src/*.cpp"
    "src/*.h"
)


# EXECUTABLE
add_executable(${PROJECT_NAME} ${ALLOCATOR} ${CONTAINER} ${ENTITY} ${SCENE_MANAGER} ${SCENE} ${UID_MANAGER} ${INFO} ${MISC} ${MAIN})


# FILTERS
source_group("allocator" FILES ${ALLOCATOR})
source_group("container" FILES ${CONTAINER})
source_group("entity" FILES ${ENTITY})
source_group("scene_manager" FILES ${SCENE_MANAGER})
source_group("scene" FILES ${SCENE})
source_group("uid_manager" FILES ${UID_MANAGER})
source_group("info" FILES ${INFO})
source_group("misc" FILES ${MISC})


# LINK
#target_link_libraries(${PROJECT_NAME})


# GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    set(WARNINGS_AND_ERRORS "-Wall -Wextra -Wfatal-errors -Wshadow -Wunreachable-code -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wold-style-cast -Wuseless-cast -Wdouble-promotion -Wformat=2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS_AND_ERRORS} -Ofast -flto -m64")
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
