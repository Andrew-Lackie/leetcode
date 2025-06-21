/*
 *  Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 *
 *  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *
 *  You must write an algorithm that runs in O(n) time and without using the division operation.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize the answer array with size equal to nums, filled with 1s.
 *
 * Perform two passes:
 *  - First pass (left to right): 
 *      For each index, compute the product of all elements to its left, 
 *      and store it in the answer array.
 *  - Second pass (right to left): 
 *      For each index, compute the product of all elements to its right, 
 *      and multiply it into the current value in the answer array.
 *
 * Return the answer array containing the product of all elements except self.
 */

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> answer(n, 1);

      int left = 1;

      for (int i = 0; i < n; i++) {
        answer[i] *= left;
        left *= nums[i];
      }

      int right = 1;

      for (int i = n - 1; i >= 0; i--) {
        answer[i] *= right;
        right *= nums[i];
      }

      return answer;
    }
};

int main() {

  vector<int> nums = {1, 2, 3, 4};

  Solution solution;

  vector<int> answer = solution.productExceptSelf(nums);

  for (int num : answer) {
    cout << num << " ";
  }

  return 0;
}



