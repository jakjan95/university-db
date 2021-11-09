cmake_minimum_required(VERSION 3.16)
project(university-db)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)
include_directories(src)
include_directories(tests)


set(HEADERS
    include/Address.hpp
    include/Database.hpp
    include/Student.hpp
    include/User.hpp)

set(SRC
    src/Address.cpp
    src/Database.cpp
    src/Student.cpp
    src/User.cpp)

set(TESTS
    tests/empty.cpp
    tests/Database.cpp)

set(FLAGS -Wall -Wextra -Werror -pedantic -Wconversion -O3)

add_library(${PROJECT_NAME}-lib STATIC ${SRC})
target_compile_features(${PROJECT_NAME}-lib PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-lib gtest)


add_executable(${PROJECT_NAME} main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

enable_testing()

add_executable(${PROJECT_NAME}-ut ${TESTS})
target_compile_features(${PROJECT_NAME}-ut PRIVATE cxx_std_17)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)
add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)
