cmake_minimum_required(VERSION 3.16)
project(cursor-token-pool CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cursortokenpool
    src/main.cpp
    src/pool.cpp
    src/quota.cpp
)

target_include_directories(cursortokenpool PRIVATE include)

if(WIN32)
    target_link_libraries(cursortokenpool PRIVATE userenv)
endif()
