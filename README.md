For running the test:

mkdir build
cd build
cmake ..
cmake --build .
ctest --verbose
(or instead, the test can be run by calling the test file manually as : ./test/test_sudoku after the build is done.)
