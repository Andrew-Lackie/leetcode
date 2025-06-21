/*
 * Given an integer array nums sorted in non-decreasing order, 
 * remove some duplicates in-place such that each unique element appears at most twice. 
 * The relative order of the elements should be kept the same.
 *
 * Since it is impossible to change the length of the array in some languages, 
 * you must instead have the result be placed in the first part of the array nums. 
 * More formally, if there are k elements after removing the duplicates, 
 * then the first k elements of nums should hold the final result. 
 * It does not matter what you leave beyond the first k elements.
 *
 * Return k after placing the final result in the first k slots of nums.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize pointers i and k to 2, since the first two elements are always valid.
 * Loop through the array starting from i.
 * At each step, compare nums[i] to nums[k - 2]:
 *   - If they are different, it means we haven’t yet added two of this value,
 *     so we copy nums[i] to nums[k] and increment k.
 *   - If they are the same, it's a third+ duplicate, so we skip it.
 *
 * This ensures that each element appears at most twice in the modified array.
 */

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
      if (nums.size() <= 2) return nums.size();
      int k = 2;
      for (int i = 2; i < nums.size(); i++) {
        if (nums[i] != nums[k - 2]) {
          nums[k++] = nums[i];
        }
      }
      return k;
    }
};

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};

  Solution solution;

  solution.removeDuplicates(nums);

  for (int num : nums) {
    cout << num << " ";
  }
}
