cmake_minimum_required(VERSION 3.16)
project(hive-core LANGUAGES C)

# 下記の流れの呼び出しが可能であることを確認したい
#     [main]
#     ↓   ↓
#  [lib_a] ↓
#      ↓  ↓
#     [lib_b]
# 
# ただしlib_aは 動的リンク(dlopen)
# lib_bは共有リンクとする

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

add_subdirectory(lib_a)
add_subdirectory(lib_b)

add_executable(main)
target_sources(main PRIVATE main.c)
target_link_libraries(main PRIVATE lib_b) # lib_aはdlopen()で開く
if(NOT WIN32)
target_link_libraries(main PRIVATE dl)
endif()

