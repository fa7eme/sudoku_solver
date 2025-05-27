#include <iostream>
#include "sudoku.h"

using namespace std;

int main()
{
    sudoku_solver test;
    test.read_file("../data/sudoku.txt");
    test.solve();
    
    return 0;
}
