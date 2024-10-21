cmake_minimum_required(VERSION 3.30)

file (GLOB_RECURSE SERIALIZER_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
file (GLOB_RECURSE SERIALIZER_HEADERS "${CMAKE_SOURCE_DIR}/src/*.hpp")
set(SERIALIZER_HEADER_DIR "${CMAKE_SOURCE_DIR}/src")

message(headers="${SERIALIZER_HEADERS}")

add_library(SerializerLib SHARED ${SERIALIZER_SOURCES})

target_include_directories(SerializerLib PUBLIC ${SERIALIZER_HEADER_DIR})

set_target_properties(SerializerLib PROPERTIES LINKER_LANGUAGE CXX)
