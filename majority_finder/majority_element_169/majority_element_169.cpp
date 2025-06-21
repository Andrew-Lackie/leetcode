/*
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times. 
 * You may assume that the majority element always exists in the array.
 */

#include <iostream>
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
 * it cannot be fully canceled out, and the final candidate is guaranteed to be the majority.
 */

class Solution {
  public: 
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
      int total = 0;
      int candidate;

      for (int i = 0; i < n; i++) {
        if (total == 0) {
          candidate = nums[i];
        }

        if (nums[i] == candidate) {
          total++;
        }
        else {
          total--;
        }
      }
      return candidate;
    }
};

int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

  Solution solution;

  int majority = solution.majorityElement(nums);

  cout << majority << endl;

  return 0;
}
