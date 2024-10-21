cmake_minimum_required(VERSION 3.30)

project(Serializer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_APPLE_SILICON_PROCESSOR arm64) # comment out for linux builds

include(SerializerLib.cmake)

add_executable("${CMAKE_PROJECT_NAME}" main.cpp)

target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE SerializerLib)

message("${SERIALIZER_HEADERS}")
