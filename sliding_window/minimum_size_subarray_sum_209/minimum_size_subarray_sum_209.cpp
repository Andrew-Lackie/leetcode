/*
 *  Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. 
 *  If there is no such subarray, return 0 instead.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * Initialize minLength to INT_MAX to track the minimum subarray length.
 * Also initialize sum and left pointer to 0.
 * Iterate through the array with a right pointer:
 *   - Add nums[right] to the running sum.
 *   - While sum >= target:
 *       - Update minLength to the minimum of itself and (right - left + 1).
 *       - Subtract nums[left] from sum and increment left to shrink the window.
 * After the loop, return 0 if minLength is still INT_MAX (no valid subarray found), otherwise return minLength.
 */

class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();
      int minLength = INT_MAX;
      int sum = 0, left = 0;

      for (int i = 0; i < n; i++) {
        sum += nums[i];
        
        while (sum >= target) {
          minLength = min(minLength, i - left + 1);
          sum -= nums[left++];
        }
      }

      return minLength == INT_MAX ? 0 : minLength;
    }
};

int main() {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  Solution solution;
  int minSubArrayLen = solution.minSubArrayLen(target, nums);

  cout << minSubArrayLen << endl;
  return 0;
}

