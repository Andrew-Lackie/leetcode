/*
 * Given an integer array nums sorted in non-decreasing order, 
 * remove the duplicates in-place such that each unique element appears only once. 
 * The relative order of the elements should be kept the same. 
 * Then return the number of unique elements in nums.
 *
 * Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
 *  * Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. 
 *    The remaining elements of nums are not important as well as the size of nums.
 *
 *  * Return k.
*/

#include <iostream>
#include <vector>

using namespace std;

/*
 *  Since the array is sorted, duplicates are adjacent. 
 *  I use i to scan the array. 
 *  Whenever I find a new unique value (nums[i] != nums[i - 1]), I write it to index k and increment k. 
 *  This way, the first k elements of nums will contain all the unique values in order.
 */

class Solution {
  public: 
    int removeDuplicates(vector<int>& nums) {
      int k = 1;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
          nums[k++] = nums[i];
        }
      }
      return k;
    }
};

int main() {

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  Solution solution;

  solution.removeDuplicates(nums);

  for (int num : nums) {
    cout << num << " ";
  }

  return 0;
}
