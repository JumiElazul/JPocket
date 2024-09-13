cmake_minimum_required(VERSION 3.21)
project(JPocket)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(SOURCES
    "src/entry_point.cpp"

    "src/application.cpp"
    "src/cpu.cpp"
    "src/window_handler.cpp"
    "src/window_specification.cpp"
    "src/gui_handler.cpp"
    "src/resources.cpp"
)

set(HEADERS
    "include/application.h"
    "include/typedefs.h"
    "include/cpu.h"
    "include/window_handler.h"
    "include/window_specification.h"
    "include/gui_handler.h"
    "include/resources.h"
)

add_executable(JPocket ${SOURCES} ${HEADERS})
target_include_directories(JPocket PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_property(TARGET JPocket PROPERTY CXX_STANDARD 20)
set_property(TARGET JPocket PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT JPocket)

add_custom_command(
    TARGET JPocket
    PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/fonts
        ${CMAKE_CURRENT_BINARY_DIR}/fonts
)

find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
target_link_libraries(JPocket PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(JPocket PRIVATE imgui::imgui)
