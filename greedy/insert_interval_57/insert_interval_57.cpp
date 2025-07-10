/*
 *  You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start 
 *  and the end of the ith interval and intervals is sorted in ascending order by starti. 
 *  You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
 *
 *  Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
 *  and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
 *
 *  Return intervals after the insertion.
 *
 *  Note that you don't need to modify intervals in-place. You can make a new array and return it.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize an empty vector `merged` to store the final result.
 * Use an index `i` to iterate through the intervals.
 *
 * Step 1: Add all intervals that end before the new interval starts:
 *   - While intervals[i][1] < newInterval[0], push intervals[i] to `merged` and increment `i`.
 *
 * Step 2: Merge all overlapping intervals with newInterval:
 *   - While intervals[i][0] <= newInterval[1], update:
 *       - newInterval[0] = min(newInterval[0], intervals[i][0])
 *       - newInterval[1] = max(newInterval[1], intervals[i][1])
 *     - Increment `i`.
 *   - Push the merged `newInterval` into `merged`.
 *
 * Step 3: Add the remaining intervals:
 *   - While i < intervals.size(), push intervals[i++] into `merged`.
 *
 * Finally, return `merged`.
 */

class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();

      vector<vector<int>> merged;

      int i = 0;
      while (i < n && intervals[i][1] < newInterval[0]) {
        merged.push_back(intervals[i]);
        i++;
      }
      while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
      }

      merged.push_back(newInterval);
 
      while (i < n && intervals[i][0] > newInterval[1]) {
        merged.push_back(intervals[i]);
        i++;
      }
 
      return merged;
    }
};

int main() {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};

  Solution solution;

  vector<vector<int>> merged = solution.insert(intervals, newInterval);

  for (vector<int>& interval : merged) {
    for (int& num : interval) {
      cout << num << ' ';
    }
    cout << endl;;
  }

  return 0;
}
