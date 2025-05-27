include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(test_sudoku test_sudoku.cpp)

target_link_libraries(test_sudoku gtest_main sudoku)

target_compile_definitions(test_sudoku PRIVATE UNIT_TEST)

include(GoogleTest)
gtest_discover_tests(test_sudoku)
