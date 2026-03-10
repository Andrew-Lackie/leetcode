/*
 * You are given an array nums consisting of n elements where each element is an
 * integer representing a color:
 *
 *    - 0 represents red
 *    - 1 represents white
 *    - 2 represents blue
 *
 * Your task is to sort the array in-place such that elements of the same color
 * are grouped together and arranged in the order: red (0), white (1), and then
 * blue (2).
 *
 * You must not use any built-in sorting functions to solve this problem.
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*
 * To solve this, intialize three pointer (left, right and i), and set a while
 * loop to terminate whenever i reaches the right pointer. If the value at i is
 * equal to 0, then swap the values at the ith and right pointer and iterate i
 * and l by 1. This works since i will always be right of the left pointer. If
 * the vlaue at i is equal to 2, then swap the the values of the ith and right
 * pointer since 2 should always be right of the other, then decrement the right
 * pointer by 1. Finally, if the value at i is equal to 1, then increment i to
 * the next value.
 */

class Solution {
public:
  void sortColors(vector<int> &colors) {
    int i = 0, l = 0, r = colors.size() - 1;

    while (i <= r) {
      int c = colors[i];
      if (c == 0) {
        swap(colors[l++], colors[i++]);
      } else if (c == 2) {
        swap(colors[r--], colors[i]);
      } else {
        i++;
      }
    }
  }
};

int main() {
  vector<int> nums1 = {1, 0, 1, 2};
  vector<int> nums2 = {2, 1, 0};

  Solution solution;

  cout << "Example 1: " << endl;

  solution.sortColors(nums1);

  for (const int &a : nums1)
    cout << a << ' ';
  cout << endl;

  cout << "Example 2: " << endl;

  solution.sortColors(nums2);

  for (const int &a : nums2)
    cout << a << ' ';
  cout << endl;

  return 0;
}
