/*
 *  Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 *
 *  You must do it in place.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * For the constant space solution to Set Matrix Zeroes:
 *
 * 1. Track whether the first row and first column need to be zeroed.
 *    - Initialize two boolean flags: `firstRowZero` and `firstColZero`.
 *    - Iterate through the first row and first column to check for any zeros.
 *
 * 2. Use the first row and column as markers.
 *    - For each cell (i, j), if matrix[i][j] == 0,
 *      set matrix[i][0] = 0 and matrix[0][j] = 0.
 *
 * 3. Iterate through the matrix (excluding the first row and column).
 *    - If matrix[i][0] == 0 or matrix[0][j] == 0, set matrix[i][j] = 0.
 *
 * 4. Zero the first row and column if needed.
 *    - If `firstRowZero` is true, set all cells in the first row to 0.
 *    - If `firstColZero` is true, set all cells in the first column to 0.
 *
 * This achieves the desired result using O(1) extra space.
 */

class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      bool isFirstColZero = false;
      bool isFirstRowZero = false;

      for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) isFirstRowZero = true;
      }

      for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) isFirstColZero = true;
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (matrix[0][j] == 0 || matrix[i][0] == 0) {
            matrix[i][j] = 0;
          }
        }
      }

      if (isFirstColZero) {
        for (vector<int>& row : matrix) {
          row[0] = 0;
        }
      }

      if (isFirstRowZero) {
        for (int i = 0; i < m; i++) {
          matrix[0][i] = 0;
        }
      }
    }
};

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  int n = matrix.size();
  int m = matrix[0].size();

  Solution solution;

  solution.setZeroes(matrix);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

