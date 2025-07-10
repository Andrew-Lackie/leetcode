/*  
 *  There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
 *  The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. 
 *  You do not know the exact y-coordinates of the balloons.
 *
 *  Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
 *  A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
 *  There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 *
 *  Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Sort the `points` array by the right boundary (points[i][1]) in ascending order.
 *
 * Initialize `arrows` to 1 — one arrow is needed at minimum.
 * Set `end` to the right boundary of the first balloon (points[0][1]).
 *
 * Iterate through the rest of the points starting at index 1:
 *   - If the left boundary of the current balloon (points[i][0]) is greater than `end`,
 *     this balloon cannot be burst by the current arrow.
 *       - Increment `arrows` by 1.
 *       - Update `end` to points[i][1], shooting a new arrow at this balloon’s end.
 *   - Otherwise, do nothing — the current arrow already bursts this balloon.
 *
 * After the loop ends, return `arrows` as the minimum number needed.
 */

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points) {
      if (points.empty()) return 0;

      sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

      int arrows = 1;
      int end = points[0][1];

      for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
          arrows++;
          end = points[i][1];
        }
      }

      return arrows;
    }
};

int main() {
  vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

  Solution solution;

  int arrows = solution.findMinArrowShots(points);

  cout << arrows << endl;

  return 0;
}



