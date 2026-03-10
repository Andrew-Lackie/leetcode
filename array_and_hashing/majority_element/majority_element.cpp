/*
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times in
 * the array. You may assume that the majority element always exists in the
 * array.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Initialize two variables:
 *  - count to track the balance of the current candidate
 *  - candidate to store the current potential majority element
 *
 * Loop through the vector:
 *  - If count is 0, assign the current value as the new candidate.
 *  - If the current value equals the candidate, increment count.
 *  - Otherwise, decrement count.
 *
 * Since the majority element appears more than n/2 times,
 * it cannot be fully canceled out, and the final candidate is guaranteed to be
 * the majority.
 */

/* O(n) time, O(n) space */
class MapSolution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> mp;
    for (int num : nums)
      mp[num]++;
    for (auto &[key, value] : mp) {
      if (value > nums.size() / 2)
        return key;
    }
    return 0;
  }
};

/* O(n) time, O(1) space */
class BoyerMooreSolution {
public:
  int majorityElement(vector<int> &nums) {
    int candidate = 0;
    int count = 0;
    for (int a : nums) {
      if (count == 0)
        candidate = a;
      count += candidate == a ? 1 : -1;
    }
    return candidate;
  }
};

int main() {

  cout << "MapSolution:" << endl;
  MapSolution map;
  BoyerMooreSolution boyer;

  vector<int> nums1 = {5, 5, 1, 1, 1, 5, 5};
  vector<int> nums2 = {2, 2, 2};

  cout << "Example 1" << endl;
  int answer1 = map.majorityElement(nums1);
  cout << answer1 << endl;

  cout << "Example 2" << endl;
  int answer2 = map.majorityElement(nums2);
  cout << answer2 << endl;

  cout << "BoyerMooreSolution:" << endl;

  cout << "Example 1" << endl;
  int answer3 = boyer.majorityElement(nums1);
  cout << answer3 << endl;

  cout << "Example 2" << endl;
  int answer4 = boyer.majorityElement(nums2);
  cout << answer4 << endl;

  return 0;
}
