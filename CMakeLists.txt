cmake_minimum_required(VERSION 3.3)
project(Artemida)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}-lm -std=gnu99")
#set(CMAKE_EXE_LINKER_FLAGS “-static-libgcc -static-libstdc++”)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.c libs/utils/linked_list.c libs/SDL2_gfx-1.0.1/SDL2_gfxPrimitives.c libs/utils/utils.c libs/vg/visual_edge.c  libs/vg/visual_graph.c libs/vg/visual_graph_viewer.c libs/vg/visual_vertex.c libs/vg/spacing_simulator.c libs/vg/spacing_simulator.h libs/graph_algorithm/graph.c  libs/utils/vector.c libs/graph_converter/graph_converter.c libs/graph_converter/graph_converter.h libs/graph_algorithm/DFS.c libs/graph_algorithm/DFS.h libs/graph_algorithm/graph_changes.c libs/graph_algorithm/graph_changes.h libs/vg/play_changes.c libs/vg/play_changes.h)
add_executable(Artemida ${SOURCE_FILES} main.c)

target_link_libraries(Artemida SDL2main SDL2)