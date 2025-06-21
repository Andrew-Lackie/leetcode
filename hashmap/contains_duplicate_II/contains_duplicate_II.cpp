/*
 *  Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> seen;

      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (seen.count(num) && abs(seen[num] - i) <= k)  return true;
        seen[num] = i;
      }
      return false;
    }
};

int main() {

  vector<int> nums1 = {1, 2, 3, 1};
  int k1 = 3;

  vector<int> nums2 = {1, 0, 1, 1};
  int k2 = 1;

  vector<int> nums3 = {1, 2, 3, 1, 2, 3};
  int k3 = 2;

  Solution solution;

  bool containsNearbyDuplicate1 = solution.containsNearbyDuplicate(nums1, k1);
  bool containsNearbyDuplicate2 = solution.containsNearbyDuplicate(nums2, k2);
  bool containsNearbyDuplicate3 = solution.containsNearbyDuplicate(nums3, k3);

  cout << "----- Example 1 -----" << endl;

  cout << containsNearbyDuplicate1 << endl;

  cout << "----- Example 2 -----" << endl;

  cout << containsNearbyDuplicate2 << endl;

  cout << "----- Example 3 -----" << endl;

  cout << containsNearbyDuplicate3 << endl;

  return 0;
}
