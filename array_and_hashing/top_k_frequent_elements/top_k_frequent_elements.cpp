/*
 * Given an integer array nums and an integer k, return the k most frequent
 * elements within the array.
 *
 * The test cases are generated such that the answer is always unique.
 *
 * You may return the output in any order.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * To solve this problem, create a frequency map, then iterate over the map and
 * store the key value pairs as vectors within a frequency bucket. Starting at
 * the end of the bucket, increment through pushing each number into the answer
 * vector, decrementing k with each push. Once k reaches 0, break. Since
 * different numbers can show up at the same frequency, the bucket must hold
 * multiple vectors. Finally, return the answer.
 */

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> mp;
    for (int num : nums)
      mp[num]++;
    vector<vector<int>> store(nums.size() + 1);

    for (const auto &[key, value] : mp)
      store[value].push_back(key);
    vector<int> answer;

    for (int i = store.size() - 1; i >= 0; --i) {
      for (int c : store[i]) {
        if (k == 0)
          break;
        answer.push_back(c);
        k--;
      }
      if (k == 0)
        break;
    }
    return answer;
  }
};

int main() {

  vector<int> nums1 = {1, 2, 2, 3, 3, 3};
  int k1 = 2;

  Solution solution1;

  vector<int> answer1 = solution1.topKFrequent(nums1, k1);

  cout << "Example 1" << endl;
  for (int a : answer1)
    cout << a << ' ';
  cout << endl;

  vector<int> nums2 = {7, 7};
  int k2 = 1;

  Solution solution2;

  vector<int> answer2 = solution1.topKFrequent(nums2, k2);

  cout << "Example 2" << endl;
  for (int a : answer2)
    cout << a << ' ';
  cout << endl;

  return 0;
}
