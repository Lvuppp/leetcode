#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        short acceptedSquares = 0, column, row;

        vector<vector<set<int>>> presumptiveSolutionsBoard(9,vector<set<int>>(9, {1,2,3,4,5,6,7,8,9}));

        for (short i = 0; i < 9; i++) {
            for (short j = 0; j < 9; j++)
            {
                if (board[i][j] != '.') {
                    column = row = 0;
                    while (column < 9)
                    {
                        presumptiveSolutionsBoard[column++][j].erase(board[i][j] - 48);
                        presumptiveSolutionsBoard[i][row++].erase(board[i][j] - 48);
                    }
                    presumptiveSolutionsBoard[i][j] = set<int>{ board[i][j] - 48 }; 
                }   
            }
        }


    }
};

int main()
{
    Solution s; 
    vector<vector<char>> v{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    s.solveSudoku(v);
}
