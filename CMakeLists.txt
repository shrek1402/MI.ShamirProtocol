cmake_minimum_required(VERSION 3.16.0)

# set the name of the project
# must immediately follow cmake_minimum_required command
project (MI)

file(GLOB_RECURSE SRC_FILES src/*.*)
file(GLOB_RECURSE NATVIS_FILES natvis/*.natvis)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${NATVIS_FILES})

include(FetchContent)
include(FindPkgConfig)

message(${SRC_FILES})

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(MI.ShamirProtocol ${SRC_FILES} ${NATVIS_FILES})
target_link_libraries(MI.ShamirProtocol gtest_main)
target_link_libraries(MI.ShamirProtocol gmock_main)
target_include_directories(MI.ShamirProtocol PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(MI.ShamirProtocol)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    find_package(Threads REQUIRED)
    pkg_check_modules(TBB REQUIRED tbb)
endif()

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17 /Zc:__cplusplus")
else(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -Werror -pedantic")
endif(MSVC)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(MI.ShamirProtocol PRIVATE Threads::Threads ${CMAKE_DL_LIBS} ${TBB_LIBRARIES})
endif()