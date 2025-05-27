#include <iostream>
#include "sudoku.h"

int main()
{
    sudoku_solver sudoku;
    sudoku.read_file("../data/sudoku.txt");
    sudoku.solve();

    return 0;
}
