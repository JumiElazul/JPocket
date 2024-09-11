cmake_minimum_required (VERSION 3.21)
project(JPocket)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED TRUE)
set(CXX_EXTENSIONS OFF)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(SOURCES
    "src/entry_point.cpp"
    "src/cpu.cpp"
)

set(HEADERS
    "include/typedefs.h"
    "include/cpu.h"
)

add_executable(JPocket ${SOURCES} ${HEADERS})
target_include_directories(JPocket PRIVATE include)

find_package(SDL2 REQUIRED)
target_link_libraries(JPocket PRIVATE SDL2::SDL2 SDL2::SDL2main)
