#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sudoku_solver
{
    private:
        vector<string> table;
        vector<string> file_content;
        vector<vector<char>> board;

    public:
        bool read_file(const string path);
        vector<vector<char>> get_sudoku_horizontally();
        vector<vector<char>> get_sudoku_vertically();
        vector<vector<char>> get_sudoku_square();
        bool is_valid(int row, int col, char c);
        bool solve();
        void print_board(vector<vector<char>> board);
        void set_file_content(vector<vector<char>> content);

};