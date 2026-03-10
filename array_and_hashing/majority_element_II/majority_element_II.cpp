/*
 * You are given an integer array nums of size n, find all elements that appear
 * more than ⌊ n/3 ⌋ times. You can return the result in any order.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int num : nums)
      mp[num]++;
    vector<int> answer;
    for (auto [key, value] : mp) {
      if (value > nums.size() / 3)
        answer.push_back(key);
    }
    return answer;
  }
};

int main() {
  Solution solution;

  vector<int> nums1 = {5, 2, 3, 2, 2, 2, 2, 5, 5, 5};
  vector<int> nums2 = {4, 4, 4, 4, 4};

  vector<int> answer1 = solution.majorityElement(nums1);

  cout << "Example 1" << endl;

  for (int num : answer1) {
    cout << num << ' ';
  }
  cout << endl;

  cout << "Example 2" << endl;
  vector<int> answer2 = solution.majorityElement(nums2);
  for (int num : answer2) {
    cout << num << ' ';
  }
  cout << endl;
}
