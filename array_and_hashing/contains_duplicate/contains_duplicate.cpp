/*
 * Given an integer array nums, return true if any value appears more than once
 * in the array, otherwise return false.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool hasDuplicate(vector<int> &nums) {
    unordered_set<int> st;

    for (const int &a : nums) {
      if (st.count(a))
        return true;
      st.insert(a);
    }
    return false;
  }
};

int main() {

  vector<int> nums1 = {1, 2, 3, 3};
  int k1 = 3;

  vector<int> nums2 = {1, 2, 3, 4};
  int k2 = 1;

  Solution solution;

  bool hasDuplicate1 = solution.hasDuplicate(nums1);
  bool hasDuplicate2 = solution.hasDuplicate(nums2);

  cout << "----- Example 1 -----" << endl;

  cout << hasDuplicate1 << endl;

  cout << "----- Example 2 -----" << endl;

  cout << hasDuplicate2 << endl;

  return 0;
}
