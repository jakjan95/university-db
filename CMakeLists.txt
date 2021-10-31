cmake_minimum_required(VERSION 3.16)
project(university-db)

include_directories(include)
include_directories(src)

set(HEADERS
    include/Address.hpp
    include/Database.hpp
    include/Student.hpp)

set(SRC
    src/Address.cpp
    src/Database.cpp
    src/Student.cpp)

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
