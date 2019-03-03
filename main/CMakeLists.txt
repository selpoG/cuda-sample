cmake_minimum_required(VERSION 3.13.0)

set(MY_TARGET main)


file(GLOB SOURCES "src/*.cpp" "src/*.c")
file(GLOB HEADERS "include/*.hpp" "include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ../lib)

add_executable(${MY_TARGET}
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${MY_TARGET} PUBLIC
    "${Boost_INCLUDE_DIRS}"
    include
    ../sample/include
)
target_link_libraries(${MY_TARGET} sample)

set_target_properties(
    ${MY_TARGET} PROPERTIES
    OUTPUT_NAME_DEBUG ${MY_TARGET}-debug
    OUTPUT_NAME_RELEASE ${MY_TARGET}
)
