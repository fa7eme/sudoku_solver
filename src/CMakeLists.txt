add_library(sudoku STATIC sudoku.cpp)

target_include_directories(sudoku PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
