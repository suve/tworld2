add_library(oshw-sdl3 STATIC "")
target_sources(oshw-sdl3 PRIVATE
    ../generic/generic.h
    ../generic/in.c
    ../generic/tile.c
    ../generic/timer.c
    oshwbind.h
    oshwbind.c
)

target_include_directories(oshw-sdl3 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/generic
    ${SDL_INCLUDE_DIR}
)

target_link_libraries(oshw-sdl3 PUBLIC ${SDL_LIBRARY})
