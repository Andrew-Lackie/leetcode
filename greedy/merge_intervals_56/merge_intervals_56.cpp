/*
 *  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
 *  and return an array of the non-overlapping intervals that cover all the intervals in the input.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * First, sort the intervals by their start time in ascending order.
 *
 * Initialize a vector `merged` to hold the merged intervals, and push the first interval from the sorted list into it.
 *
 * Iterate through the remaining intervals:
 *   - Let `curr` be the current interval.
 *   - Let `last` be the last interval in `merged`.
 *
 *   - If `curr[0] <= last[1]`, the intervals overlap:
 *       - Merge them by updating `last[1]` to `max(last[1], curr[1])`.
 *       - (This modifies the last interval in `merged`.)
 *
 *   - Otherwise (no overlap), push `curr` into `merged`.
 *
 * After processing all intervals, return `merged`.
 */

class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int n = intervals.size();

      sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a < b; });

      vector<vector<int>> answer;
      answer.push_back(intervals[0]);

      for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= answer.back()[1]) {
          answer.back()[1] = max(answer.back()[i], intervals[i][1]);
        }
        else {
          answer.push_back(intervals[i]);
        }
      }

      return answer;
    }
};

int main() {
  vector<vector<int>> intervals = {{ 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 }};

  Solution solution;

  vector<vector<int>> answer = solution.merge(intervals);

  for (vector<int>& interval : answer) {
    for (int& a : interval) {
      cout << a << ' ';
    }
    cout << endl;
  }

  return 0;
}

