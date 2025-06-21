/*
 *  You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 *
 *  Find two lines that together with the x-axis form a container, such that the container contains the most water.
 *
 *  Return the maximum amount of water a container can store.
 *
 *  Notice that you may not slant the container.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize two pointers i and j, and a variable to track the maximum area.
 * While i < j:
 *   - Compute the area as the minimum of the two heights (height[i], height[j]) 
 *     multiplied by the distance between the pointers (j - i).
 *   - Update the maximum area if the current area is larger.
 *   - If height[i] is less than height[j], increment i to potentially find a taller line.
 *   - Otherwise, decrement j.
 * Return the maximum area found.
 */

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int i = 0, j = height.size() - 1;
      int area = 0;

      while (i < j) {
        area = max(area, min(height[i], height[j]) * (j - i));
        if (height[i] < height[j]) i++;
        else j--;
      }

      return area;
    }
};

int main() {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  Solution solution;
  int area = solution.maxArea(height);

  cout << area << endl;
  return 0;
}



