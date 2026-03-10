/*
 *  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 *
 *  You must write an algorithm that runs in O(n) time.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
 * Create an unordered_set containing all unique numbers from nums for O(1) lookups.
 *
 * Iterate through each number in the set:
 *   - If the set does NOT contain (num - 1), then this number is the start of a sequence.
 *   - Initialize a length counter and increment a value while consecutive numbers exist in the set.
 *   - After the inner loop ends, update the max length if the current sequence is longer.
 *
 * Return the maximum sequence length found.
 */

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> nSet(nums.begin(), nums.end());

      int maxLen = 0;

      for (int num : nSet) {
        if (!nSet.count(num - 1)) {
          int len = 0;
          int val = num;
          while (nSet.count(val)) {
            val++;
            len++;
          }
          maxLen = max(maxLen, len);
        }
      }
      return maxLen;
    }
};

int main() {
  vector<int> nums1 = {100, 4, 200, 1, 3, 2};
  vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  Solution solution;

  int longestConsecutive1 = solution.longestConsecutive(nums1);
  int longestConsecutive2 = solution.longestConsecutive(nums2);

  cout << "----- Example 1 -----" << endl;

  cout << longestConsecutive1 << endl;

  cout << "----- Example 2 -----" << endl;

  cout << longestConsecutive2 << endl;

  return 0;
}


