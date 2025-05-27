#include "gtest/gtest.h"
#include "../src/sudoku.h"

class SudokuTest : public ::testing::Test {
protected:
    sudoku_solver solver;

    void SetUp() override {
        solver.set_file_content({
            "53__7____",
            "6__195___",
            "_98___6__",
            "8__6___3_",
            "4__8_3__1",
            "7__2___6_",
            "_6____28_",
            "___419__5",
            "____8__79"
        });
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
    EXPECT_EQ(columns[1][1], '_');
    EXPECT_EQ(columns[8][8], '9');
}

TEST_F(SudokuTest, Test3x3Squares) {
    auto squares = solver.get_sudoku_square();
    ASSERT_EQ(squares.size(), 9);

    vector<char> expected = {'5', '3', '_', '6', '_', '_', '_', '9', '8'};
    EXPECT_EQ(squares[0], expected);

    vector<char> bottom_ight = {'2','8','_','_','_','5','_','7','9'};
    EXPECT_EQ(squares[8], bottomRight);
}
