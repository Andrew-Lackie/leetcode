/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
 * The order of the elements may be changed. 
 * Then return the number of elements in nums which are not equal to val.
 *
 *  Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
 *
 *    * Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
 *      The remaining elements of nums are not important as well as the size of nums.
 *
 *    * Return k.
 */

#include <iostream>
#include <vector>

using namespace std;

/* 
 * Initialize two pointers: 
 *  - i scans every element of the array
 *  - k tracks the position to overwrite the next valid (non-val) element
 *
 * For every nums[i] that is not equal to val, we copy it to nums[k] and increment k.
 * This way, all non-val elements are compacted at the front of the array in-place.
 * 
 * We don't care about values beyond index k, as the problem only requires the first k elements to be correct.
 */

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
      int k = 0;

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
          nums[k++] = nums[i];
        }
      }
      return k;
    }
};

int main() {

  Solution solution;

  vector<int> nums = {3, 2, 2, 3};
  int val = 3;

  solution.removeElement(nums, val);

  for (int num : nums) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
}
