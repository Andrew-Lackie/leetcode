/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, 
 * but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
 * where the first m elements denote the elements that should be merged, 
 * and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Initialize three pointers:
 *   - i = m - 1 → last valid element in nums1
 *   - j = n - 1 → last element in nums2
 *   - k = m + n - 1 → last index in nums1
 *
 * Use a while loop to iterate backward, stopping when all elements from nums2 have been placed (i.e., while j >= 0).
 *
 * At each step:
 *   - If nums1[i] > nums2[j], place nums1[i] at nums1[k] and decrement i and k.
 *   - Otherwise, place nums2[j] at nums1[k] and decrement j and k.
 *
 * This ensures we fill nums1 from the back, avoiding overwriting any useful data.
 */

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m - 1;
      int j = n - 1;
      int k = n + m - 1;

      while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
          nums1[k--] = nums1[i--];
        }
        else {
          nums1[k--] = nums2[j--];
        }
      }
    }
};

int main() {

  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  Solution solution;

  solution.merge(nums1, m, nums2, n);

  for (int num : nums1) {
      cout << num << " ";
  }
  cout << endl;

  return 0;
};
