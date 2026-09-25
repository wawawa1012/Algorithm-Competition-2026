cmake_minimum_required(VERSION 4.1)
project(Algorithm_Competition_2026)

set(CMAKE_CXX_STANDARD 17)

file(GLOB PROBLEM_SOURCES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/recovery/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/topics/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/contests/*.cpp")

foreach (src ${PROBLEM_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    add_executable(${target_name} ${src})
endforeach ()
