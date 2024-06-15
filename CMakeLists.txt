cmake_minimum_required(VERSION 3.1)
project(main VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LoremIpsum_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/LoremIpsum/bin)
find_package(LoremIpsum REQUIRED)

message("LoremIpsum found: " ${LoremIpsum_FOUND})
message("LoremIpsum inc:   " ${LoremIpsum_INCLUDES})
message("LoremIpsum libs:  " ${LoremIpsum_LIBS})
message("LoremIpsum libs:  " ${LoremIpsum_LIBRARIES})



add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE LoremIpsum::LoremIpsum)
