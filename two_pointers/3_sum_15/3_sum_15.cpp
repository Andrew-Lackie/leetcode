/*
 *  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 *  Notice that the solution set must not contain duplicate triplets.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Sort the array in non-decreasing order and initialize the triplets vector.
 * Iterate through the array using index i. If nums[i] is equal to nums[i - 1], skip to avoid duplicate triplets.
 * For each i, initialize two pointers: start = i + 1 and end = n - 1.
 * While start < end:
 *   - Compute the sum of nums[i], nums[start], and nums[end].
 *   - If the sum is 0:
 *       - Append {nums[i], nums[start], nums[end]} to triplets.
 *       - Move start and end to the next distinct values to skip duplicates.
 *       - Then increment start and decrement end.
 *   - If the sum is greater than 0, decrement end to reduce the sum.
 *   - If the sum is less than 0, increment start to increase the sum.
 * Return the triplets vector.
 */

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      vector<vector<int>> triplets;

      for (int i = 0; i < n; i++) {
        int first = nums[i];
        if (i > 0 && first == nums[i - 1]) continue;
        int start = i + 1;
        int end = n - 1;
        while (start < end) {
          int second = nums[start];
          int third = nums[end];
          int sum = first + second + third;
          if (sum == 0) {
            triplets.push_back({first, second, third});
            while (start < end && nums[start] == nums[start + 1]) start++; 
            while (start < end && nums[end] == nums[end - 1]) end--; 
            start++;
            end--;
          }
          else if (sum > 0) start++;
          else end--;
        }
      }
      return triplets;
    }
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  Solution solution;

  vector<vector<int>> triplets = solution.threeSum(nums);

  for (vector<int> triplet : triplets) {
    for (int num : triplet) {
      cout << num << endl;
    }
  }

  return 0;
}


