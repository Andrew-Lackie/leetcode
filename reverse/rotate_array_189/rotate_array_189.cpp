/* 
 *  Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:

    /*
    * The optimal solution uses a three-step reversal approach:
    *   1. Reverse the entire array
    *   2. Reverse the first k elements
    *   3. Reverse the remaining n - k elements
    *
    * This simulates rotating the array to the right by k steps in-place.
    */

    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k %= n;

      std::reverse(nums.begin(), nums.end());
      std::reverse(nums.begin(), nums.begin() + k);
      std::reverse(nums.begin() + k, nums.end());
    }

    void naive_rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k %= n;

      for (int i = 0; i < k; i++) {
        int curr = nums[0];
        for (int j = 1; j < n; j++) {
          int temp = nums[j];
          nums[j] = curr;
          curr = temp;
        }
        nums[0] = curr;
      }
    }
};

int main() {

  vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};

  Solution solution;

  solution.rotate(nums1, k);

  for (int num : nums1) {
    cout << num << " ";
  }

  cout << "\n";
  solution.naive_rotate(nums2, k);

  for (int num : nums2) {
    cout << num << " ";
  }

  return 0;
}
