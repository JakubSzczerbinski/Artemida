cmake_minimum_required(VERSION 3.3)
project(Artemida)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS}-lm -std=gnu99")
#set(CMAKE_EXE_LINKER_FLAGS “-static-libgcc -static-libstdc++”)

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.c src/utils/linked_list.c src/SDL2_gfx-1.0.1/SDL2_gfxPrimitives.c src/utils/utils.c src/vg/visual_edge.c src/vg/visual_graph.c src/vg/visual_graph_viewer.c src/vg/visual_vertex.c src/vg/spacing_simulator.c src/vg/spacing_simulator.h src/graph_algorithm/graph.c src/utils/vector.c src/graph_converter/graph_converter.c src/graph_converter/graph_converter.h src/graph_algorithm/DFS.c src/graph_algorithm/DFS.h src/graph_algorithm/graph_changes.c src/graph_algorithm/graph_changes.h src/vg/play_changes.c src/vg/play_changes.h src/utils/queue.c src/utils/queue.h)
add_executable(Artemida ${SOURCE_FILES} main.c)

target_link_libraries(Artemida SDL2main SDL2)