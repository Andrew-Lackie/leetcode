/*
 *  You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
 *  You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Start by taking the transpose of the matrix:
 *  - Iterate through all the rows i, and all the columns starting at j = i, then swap the values at each matrix[i][j] and matrix[j][i].
 * 
 * At this point, the matrix will in the correct position with the cols reversed:
 *  - Reverse the cols of the matrix.
 */

class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      
      for (int i = 0; i < n; i++) {
        for (int j = i; j < m; j++) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }

      for (auto& row : matrix) {
        reverse(row.begin(), row.end());
      }
    }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int n = matrix.size();
  int m = matrix[0].size();

  Solution solution;

  solution.rotate(matrix);

  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cout << matrix[i][j] << " ";
      }
      cout << endl;
  }

  return 0;
}


