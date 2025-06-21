/*
 *  You are given an integer array nums. 
 *  You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
 *
 *  Return true if you can reach the last index, or false otherwise.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  /*
  * Initialize maxReach to 0.
  * Iterate through the array:
  *   - If the current index i is greater than maxReach, return false (you can't reach this point).
  *   - Otherwise, update maxReach to the maximum of maxReach and i + nums[i].
  * If the loop completes, it means you can reach the end — return true.
  */
  public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      int maxReach = nums[0];

      for (int i = 0; i < n; i++) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
      }
      return true;
    }
};

int main() {

  vector<int> nums = {2, 3, 1, 1, 4};

  Solution solution;

  bool canJump = solution.canJump(nums);

  cout << canJump << endl;

  return 0;
}
