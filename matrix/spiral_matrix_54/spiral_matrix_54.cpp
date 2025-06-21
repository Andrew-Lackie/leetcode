/*
 *  Given an m x n matrix, return all elements of the matrix in spiral order.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize four pointers: top, bottom, left, and right.
 * Set top = 0, bottom = n - 1, left = 0, right = m - 1.
 *
 * While left <= right and top <= bottom:
 *
 *  - Traverse left to right along the top row, then increment top.
 *  - Traverse top to bottom along the right column, then decrement right.
 *  - If top <= bottom, traverse right to left along the bottom row, then decrement bottom.
 *  - If left <= right, traverse bottom to top along the left column, then increment left.
 *
 * Continue until all elements are visited in spiral order.
 */

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      vector<int> answer;

      int left = 0, right = m - 1, top = 0, bottom = n - 1;

      while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
          answer.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
          answer.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
          for (int i = right; i >= left; i--) {
            answer.push_back(matrix[bottom][i]);
          }
          bottom--;
        }

        if (left <= right) {
          for (int i = bottom; i >= top; i--) {
            answer.push_back(matrix[i][left]);
          }
          left++;
        }
      }

      return answer;
    }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  
  Solution solution;

  vector<int> spiralOrder = solution.spiralOrder(matrix);

  for (const int& num : spiralOrder) {
    cout << num << endl;
  }

  return 0;
}

