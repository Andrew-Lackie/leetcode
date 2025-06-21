/*
 *  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * To solve this problem, initialize two vectors of size n, both filled with 0:
 *   - In the first pass (left to right), compute the maximum height to the left of each index,
 *     including the current index, and store it in left[i].
 *   - In the second pass (right to left), compute the maximum height to the right of each index,
 *     including the current index, and store it in right[i].
 *   - In the final pass, iterate from 0 to n - 1:
 *       - At each index, calculate water = min(left[i], right[i]) - height[i]
 *       - If water > 0, add it to the total.
 *
 * Return the total trapped water.
 */

class Solution {
  public:
    int trap(vector<int>& height) {
      int n = height.size();
      if (n == 0) return 0;

      int total = 0;
      vector<int> left(n, 0), right(n, 0);

      int localMax = 0;

      for (int i = 0; i < n; i++) {
        localMax = max(localMax, height[i]);
        left[i] = localMax;
      }

      localMax = 0;

      for (int i = n - 1; i >= 0; i--) {
        localMax = max(localMax, height[i]);
        right[i] = localMax;
      }

      for (int i = 0; i < n; i++) {
        int diff = min(left[i], right[i]) - height[i];
        total += diff < 0 ? 0 : diff;
      }

      return total;
    }
};

int main() {
  vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

  Solution solution;

  int total = solution.trap(height);

  cout << total << endl;

  return 0;
}
