/*
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
 * Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
 *
 *   * 0 <= j <= nums[i] and
 *   * i + j < n
 *
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize three variables:
 *   - farthest: tracks the farthest index reachable so far.
 *   - jump: counts the total number of jumps made.
 *   - currentEnd: marks the end of the current jump range.
 *
 * Iterate through the array (excluding the last index):
 *   - Update farthest to the maximum of farthest and i + nums[i].
 *   - If i reaches currentEnd:
 *       - Increment jump (we're making a new jump),
 *       - Set currentEnd to farthest (start the next jump range).
 *
 * Return the total number of jumps.
 */

class Solution {
  public:
    int jump(vector<int>& nums) {
      int farthest = 0;
      int jump = 0;
      int currentEnd = 0;

      for (int i = 0; i < nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        
        if (i == currentEnd) {
          jump++;
          currentEnd = farthest;
        }
      }
      return jump;
    }
};
