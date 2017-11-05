cmake_minimum_required(VERSION 3.7)
project(boost_asio_npcbook)

set(CMAKE_CXX_STANDARD 17)
set(PROJECTNAME_ARCHITECTURE "x64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

set(SOURCE_FILES
        src/main.cpp
        src/main.hpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(Boost 1.64.0 REQUIRED)

if (Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
endif ()

target_link_libraries(${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "optional")

