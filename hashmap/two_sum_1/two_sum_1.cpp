/*
 *  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *
 *  You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Initialize a hashmap to store previously seen numbers and their indices.
 *
 * Iterate through the `nums` array:
 *  - For each element, compute the difference between the target and the current number.
 *  - If the difference exists in the map, return a vector containing the stored index and the current index.
 *  - Otherwise, store the current number and its index in the map.
 *
 * If no such pair is found by the end, return an empty vector.
 */

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> numsMap;

      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int diff = target - num;
        if (numsMap.count(diff)) return {numsMap[diff], i};
        numsMap[num] = i;
      }

      return {};
    }
};

int main() {

  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution solution;

  vector<int> twoSum = solution.twoSum(nums, target);

  for (const int& num : twoSum) cout << num << endl;

  return 0;
}



