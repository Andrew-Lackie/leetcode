/*
 *  You are given a sorted unique integer array nums.
 *
 *  A range [a,b] is the set of all integers from a to b (inclusive).
 *
 *  Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
 *  That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
 *
 *  Each range [a,b] in the list should be output as:
 *
 *    - "a->b" if a != b
 *    - "a" if a == b
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
      int n = nums.size();
      vector<string> ranges;
      int start = 0;

      for (int i = 1; i <= n; i++) {
        if (i == n || nums[i] != nums[i - 1] + 1) {
          if (start == i - 1) {
            ranges.push_back(to_string(nums[start]));
          }
          else {
            ranges.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
          }
          start = i;
        }
      }
      return ranges;
    }
};

int main() {
  vector<int> nums = {0, 1, 2, 4, 5, 7};

  Solution solution;

  vector<string> ranges = solution.summaryRanges(nums);

  for (const string& range : ranges) {
    cout << range << endl;
  }

  return 0;
}
