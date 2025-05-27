#include "gtest/gtest.h"
#include "../src/sudoku.h"

class SudokuTest : public ::testing::Test {
protected:
    sudoku_solver solver;

    void SetUp() override {
        vector<vector<char>> board = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };

        solver.set_file_content(board);
    }
};

TEST_F(SudokuTest, TestHorizontalRows) {
    auto rows = solver.get_sudoku_horizontally();
    ASSERT_EQ(rows.size(), 9);
    EXPECT_EQ(rows[0][0], '5');
    EXPECT_EQ(rows[1][3], '1');
    EXPECT_EQ(rows[8][8], '9');
}

TEST_F(SudokuTest, TestVerticalColumns) {
    auto columns = solver.get_sudoku_vertically();
    ASSERT_EQ(columns.size(), 9);
    EXPECT_EQ(columns[0][0], '5');
    EXPECT_EQ(columns[1][1], '.');
    EXPECT_EQ(columns[8][8], '9');
}

TEST_F(SudokuTest, Test3x3Squares) {
    auto squares = solver.get_sudoku_square();
    ASSERT_EQ(squares.size(), 9);

    vector<char> expected = {'5', '3', '.', '6', '.', '.', '.', '9', '8'};
    EXPECT_EQ(squares[0], expected);

    vector<char> bottom_right = {'2','8','.','.','.','5','.','7','9'};
    EXPECT_EQ(squares[8], bottom_right);
}

TEST_F(SudokuTest, IsValidTrueForEmptyCell) {
    EXPECT_TRUE(solver.is_valid(0, 2, '4'));
}

//suggesting a number which is already in the row
TEST_F(SudokuTest, IsValidFalseRowSuggestion) {
    EXPECT_FALSE(solver.is_valid(0, 2, '5'));
    EXPECT_FALSE(solver.is_valid(7, 8, '9'));
}

//suggesting a number which is already in the column
TEST_F(SudokuTest, IsValidFalseColumnSuggestion) {
    EXPECT_FALSE(solver.is_valid(2, 0, '6'));
    EXPECT_FALSE(solver.is_valid(3, 8, '9'));
}

//suggesting a number which is already in the box(3*3)
TEST_F(SudokuTest, IsValidFalseBoxSuggestion) {
    EXPECT_FALSE(solver.is_valid(1, 2, '3'));
    EXPECT_TRUE(solver.is_valid(3, 0, '2'));
}