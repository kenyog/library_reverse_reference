
add_library(lib_b SHARED)
target_sources(lib_b PRIVATE lib_b.c)
target_include_directories(lib_b PUBLIC .)

