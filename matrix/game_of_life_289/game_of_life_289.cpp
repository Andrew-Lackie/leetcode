/*
 *  The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). 
 *  Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
 *
 *    - Any live cell with fewer than two live neighbors dies as if caused by under-population.
 *    - Any live cell with two or three live neighbors lives on to the next generation.
 *    - Any live cell with more than three live neighbors dies, as if by over-population.
 *    - Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
 *
 *  The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. 
 *  In this process, births and deaths occur simultaneously.
 *
 *  Given the current state of the board, update the board to reflect its next state.
 *
 *  Note that you do not need to return anything.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Define a vector of 8 direction pairs representing all possible neighbor offsets.
 *
 * For each cell in the grid:
 *   - Iterate over all 8 directions to count the number of live neighbors.
 *   - For each neighbor, add its value masked with 1 (original state) to a local sum,
 *     only if the neighbor is within bounds.
 *
 * Based on the current cell’s original state and the number of live neighbors:
 *   - If the cell should stay alive or become alive, set the second bit (bit 1) to 1 using |= 2.
 *   - This encodes the next state without overwriting the current one.
 *
 * After processing the entire board, perform a final pass:
 *   - Right shift each cell by 1 to update the cell with its new state (bit 1 → bit 0).
 */

class Solution {
  public:
    void gameOfLife(vector<vector<int>>& board) {
      int n = board.size();
      int m = board[0].size();

      vector<pair<int, int>> directions = {
        { -1, -1 }, { -1, 0 }, { -1, 1 },
        {  0, -1 },            {  0, 1 },
        {  1, -1 }, {  1, 0 }, {  1, 1 },
      };

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int sum = 0;
          for (auto& [dx, dy] : directions) {
            int r = dx + i;
            int c = dy + j;

            if (r >= 0 && r < n && c >= 0 && c < m) sum += board[r][c] & 1;
          }

          int num = board[i][j] & 1;

          if ((num == 1 && (sum == 2 || sum == 3)) || (num == 0 && (sum == 3))) board[i][j] |= (1 << 1);
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          board[i][j] >>= 1;
        }
      }
    }
};

int main() {

  vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

  Solution solution;

  solution.gameOfLife(board);

  for (const vector<int>& vec : board) {
    for (const int& num : vec) {
      cout << num << ' ';
    }
    cout << endl;
  }

  return 0;
}
