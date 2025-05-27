#include <fstream>
#include <sstream>
#include <map>

#include "sudoku.h"

bool sudoku_solver::read_file(const string path)
{
    ifstream file(path, ios::in);
    string line;
    board.clear();
    if (!file.is_open()) {
        return false;
    }

    while (getline(file, line)) {
        if (!line.empty()) {
            // vector<char> row(line.begin(), line.end());
            board.emplace_back(line.begin(), line.end());
        }
    }

    return true;

}

//Next three functions are not used in the final code, but they were part of my first approach, I kept them here
//to document and show how I came up with the final solution. 

//Accessing the board members, row by row
vector<vector<char>> sudoku_solver::get_sudoku_horizontally()
{
    return board;
}

//Accessing the board members, column by column
vector<vector<char>> sudoku_solver::get_sudoku_vertically()
{
    vector<vector<char>> columns(9);

    for (const auto row : board) {
        for (size_t col = 0; col < 9; ++col) {
            columns[col].push_back(row[col]);
        }
    }

    return columns;
}

//Accessing the board members, square by square
vector<vector<char>> sudoku_solver::get_sudoku_square()
{
    vector<vector<char>> squares(9);
    // vector<vector<char>> rows = get_sudoku_horizontally();

    for (int blockRow = 0; blockRow < 3; ++blockRow) {
        for (int blockCol = 0; blockCol < 3; ++blockCol) {
            int squareIndex = blockRow * 3 + blockCol;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int row = blockRow * 3 + i;
                    int col = blockCol * 3 + j;
                    squares[squareIndex].push_back(board[row][col]);
                }
            }
        }
    }

    // cout<<"the square : " << endl;
    // for (size_t i = 0; i < 9; ++i) {
    //     cout << "square " <<i<< ": ";
    //     for (char c : squares[i]) {
    //         cout<<c << ' ';
    //     }
    //     cout<<endl;
    // }

    return squares;
}

bool sudoku_solver::is_valid(int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == c || board[i][col] == c)
            return false;
    }

    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[box_row + i][box_col + j] == c)
                return false;

    return true;
}

bool sudoku_solver::solve() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.' || board[row][col] == '-') {
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (is_valid(row, col, ch)) {
                        board[row][col] = ch;
                        if (solve()) {
                            return true;
                        }
                        board[row][col] = '.';//or -
                    }
                }
                return false;
            }
        }
    }
    print_board(board);
    return true;
}

void sudoku_solver::print_board(vector<vector<char>> board) {
    for (const auto row : board) {
        for (char number : row) {
            cout << number << ' ';
        }
        cout << endl;
    }
}

void sudoku_solver::set_file_content(vector<vector<char>> content)
{
    board = content;
}
