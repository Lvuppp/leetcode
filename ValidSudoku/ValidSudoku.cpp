#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (short i = 0; i < 3; i++) {
            for (short j = 0; j < 3; j++) {
                if (!isSquareValid(board, i, j)) {
                    return false;
                }
            }
        }

        return isLinesValid(board);
    }

    bool isSquareValid(const vector<vector<char>>& board, const short& row, const short& col) {
        vector<short> nums(9, 0);

        for (short i = row * 3; i < (row + 1) * 3; i++) {
            for (short j = col * 3; j < (col + 1) * 3; j++) {

                if (isdigit(board[i][j])) {
                    nums[board[i][j] - 49]++;

                    if (nums[board[i][j] - 49] > 1) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isLinesValid(const vector<vector<char>>& board)
    {
        for (short i = 0; i < 9; i++) {
            vector<short> nums(9, 0);

            for (short j = 0; j < 9; j++) {

                if (isdigit(board[i][j])) {
                    nums[board[i][j] - 49]++;

                    if (nums[board[i][j] - 49] > 1) {
                        return false;
                    }
                }
            }
        }

        for (short i = 0; i < 9; i++) {
            vector<short> nums(9, 0);

            for (short j = 0; j < 9; j++) {

                if (isdigit(board[j][i])) {
                    nums[board[j][i] - 49]++;

                    if (nums[board[j][i] - 49] > 1) {
                        return false;
                    }

                }
            }
        }
        return true;
    }

};



int main()
{
    vector<vector<char>> vec{       {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
        , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
            , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
            , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
            , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
            , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
            , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
            , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
        , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }};
    Solution s;
    s.isValidSudoku(vec);
}