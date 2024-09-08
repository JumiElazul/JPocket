project(${project_name})

set(SOURCES
    "src/entry_point.cpp"
    "src/cpu.cpp"
)

set(HEADERS
    "include/typedefs.h"
    "include/cpu.h"
)

add_executable(${project_name} ${SOURCES} ${HEADERS})
target_include_directories(${project_name} PRIVATE include)

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(IMGUI REQUIRED)
#find_package(tinyfiledialogs REQUIRED)

target_link_libraries(${project_name} PRIVATE SDL2::SDL2 SDL2::SDL2main)
#target_link_libraries(${project_name} PRIVATE SDL2_image::SDL2_image-static)
#target_link_libraries(${project_name} PRIVATE imgui::imgui)
#target_link_libraries(${project_name} PRIVATE tinyfiledialogs::tinyfiledialogs)
