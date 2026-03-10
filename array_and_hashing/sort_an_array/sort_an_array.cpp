/*
 * You are given an array of integers nums, sort the array in ascending order
 * and return it.
 *
 * You must solve the problem without using any built-in functions in O(nlog(n))
 * time complexity and with the smallest space complexity possible.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Solving this problem simply requires a merge sort (or a heap sort to optimize
 * space complexity to n(1))
 */

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right)
      return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l1(n1), l2(n2);

    for (int i = 0; i < n1; ++i)
      l1[i] = nums[left + i];
    for (int i = 0; i < n2; ++i)
      l2[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
      nums[k++] = l1[i] <= l2[j] ? l1[i++] : l2[j++];

    while (i < n1)
      nums[k++] = l1[i++];
    while (j < n2)
      nums[k++] = l2[j++];
  }
};

int main() {
  vector<int> nums1 = {10, 9, 1, 1, 1, 2, 3, 1};
  vector<int> nums2 = {5, 10, 2, 1, 3};

  Solution solution;

  // Example 1
  cout << "Example 1" << endl;
  vector<int> l1 = solution.sortArray(nums1);
  for (const int &a : l1)
    cout << a << endl;

  // Example 2
  cout << "Example 2" << endl;
  vector<int> l2 = solution.sortArray(nums2);
  for (const int &a : l2)
    cout << a << endl;
}
