
add_library(lib_a SHARED)
target_sources(lib_a PRIVATE lib_a.c)
target_link_libraries(lib_a PRIVATE lib_b)
target_include_directories(lib_a PUBLIC .)

