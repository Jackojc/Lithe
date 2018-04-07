cmake_minimum_required(VERSION 2.8)
set(PROJECT_NAME lithe)
project(${PROJECT_NAME})


# SOURCE FILES
set(MAIN main.cpp)



# EXECUTABLE
add_executable(
    ${PROJECT_NAME}
    ${MAIN}
)


# GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    set(WARNINGS_AND_ERRORS "-Wall -Wextra -Wfatal-errors -Wshadow -Wunreachable-code -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wold-style-cast -Wuseless-cast -Wdouble-promotion -Wformat=2")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS_AND_ERRORS} -Ofast -flto -m64")
endif(CMAKE_COMPILER_IS_GNUCXX)


#MSVC
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++14 /W3 /Ox /GL")
endif(MSVC)


# PROPERTIES
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
