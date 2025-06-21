/*
 *  Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 *    - Each row must contain the digits 1-9 without repetition.
 *    - Each column must contain the digits 1-9 without repetition.
 *    - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 *
 *  Note:
 *    - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 *    - Only the filled cells need to be validated according to the mentioned rules.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

/*
 * Initialize three vectors of unordered sets, each of size 9:
 *   - `rows[i]` will store the digits seen in row i
 *   - `cols[j]` will store the digits seen in column j
 *   - `squares[k]` will store the digits seen in the k-th 3x3 sub-box
 *
 * Loop through each cell in the board using a nested loop:
 *   - Outer loop: iterate over each row index `i`
 *   - Inner loop: iterate over each column index `j`
 *
 *   - For each cell (i, j):
 *       - If the character is '.', skip it (continue)
 *       - Compute the square index as: (i / 3) * 3 + (j / 3)
 *       - If the character already exists in:
 *           - `rows[i]`, or
 *           - `cols[j]`, or
 *           - `squares[square_index]`
 *         → return false (duplicate found)
 *       - Otherwise, insert the character into all three sets
 *
 * If all cells are processed with no duplicates, return true (board is valid)
 */

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
      vector<unordered_set<char>> rows(9);
      vector<unordered_set<char>> cols(9);
      vector<unordered_set<char>> squares(9);

      for (int i = 0; i < board.size(); i++) {
        const vector<char>& row = board[i];

        for (int j = 0; j < row.size(); j++) {
          const char& c = row[j];

          if (c == '.') continue;

          if (rows[i].count(c)) return false;
          if (cols[i].count(c)) return false;
          if (squares[((i / 3) * 3) + (j / 3)].count(c)) return false;

          rows[i].insert(c);
          cols[i].insert(c);
          squares[((i / 3) * 3) + (j / 3)].insert(c);
        }
      }
      return true;
    }
};

int main() {

  vector<vector<char>> board = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  Solution solution;

  bool isValidSudoku = solution.isValidSudoku(board);

  cout << isValidSudoku << endl;

  return 0;
}

