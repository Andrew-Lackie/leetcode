/*
 * You are given an array of integers nums and an integer k, return the total
 * number of subarrays whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * To solve this, initialize a prefix sum, a total to hold the sub array count
 * and a sum to hold thetotal sum of the numbers in the array. Loop through each
 * number, increasing the sum by num. Find the difference between the sum and k.
 * If the difference exists in the prefix sum n times, then there exists n
 * subarrays that equal to k; therefore, increment the total by n. Finally,
 * increment the prefix array at the new sum, and return total.
 *
 * Make sure to set the prefix sum at position 0 to value 1 (if the first value
 * of the array is k, then the difference between the sum and k will be 0,
 * iterating the total by 1).
 */

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int total = 0, sum = 0;
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    for (int num : nums) {
      sum += num;
      int diff = sum - k;
      total += prefixSum[diff];
      prefixSum[sum]++;
    }
    return total;
  }
};

int main() {

  Solution solution;

  int k1 = 2;
  vector<int> nums1 = {2, -1, 1, 2};

  int k2 = 4;
  vector<int> nums2 = {4, 4, 4, 4, 4, 4};

  cout << "Example 1" << endl;
  int answer1 = solution.subarraySum(nums1, k1);
  cout << answer1 << endl;

  cout << "Example 2" << endl;
  int answer2 = solution.subarraySum(nums2, k2);
  cout << answer2 << endl;

  return 0;
}
