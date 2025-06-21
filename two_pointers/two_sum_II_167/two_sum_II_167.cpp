/*
 *  Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
 *  Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
 *
 *  Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
 *
 *  The tests are generated such that there is exactly one solution. You may not use the same element twice.
 *
 *  Your solution must use only constant extra space.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize two pointers: i = 0 (start of the array) and j = n - 1 (end of the array).
 * While i < j:
 *   - Compute the sum of numbers[i] + numbers[j].
 *   - If the sum equals the target, return {i + 1, j + 1} (1-based indices as required).
 *   - If the sum is greater than the target, decrement j to reduce the sum.
 *   - If the sum is less than the target, increment i to increase the sum.
 * If no such pair is found, return an empty array.
 */

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int n = numbers.size();
      int i = 0;
      int j = n - 1;

      while (j > i) {
        int sum = numbers[j] + numbers[i];

        if (sum == target) return {++i, ++j};
        else if (sum > target) j--;
        else i++;
      }

      return {};
    }
};

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;

  Solution solution;

  vector<int> indices = solution.twoSum(numbers, 9);

  for (const int &num : indices) {
    cout << num << endl;  
  }

  return 0;
}
