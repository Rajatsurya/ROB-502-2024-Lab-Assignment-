cmake_minimum_required(VERSION 3.10)

project(lab21)

find_package(lcm REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
include(${LCM_USE_FILE})

find_package(Threads REQUIRED)
 
lcm_wrap_types(
  CPP_HEADERS cpp_headers
)

lcm_add_library(mylcmtypes CPP ${cpp_headers})
target_include_directories(mylcmtypes INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

add_executable(visualizer visualizer.cpp)
target_link_libraries(visualizer lcm Qt5::Widgets)

add_executable(robot_main robot_main.cpp)
target_link_libraries(robot_main lcm)