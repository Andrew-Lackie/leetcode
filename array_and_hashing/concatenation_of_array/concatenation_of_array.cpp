/*
 * You are given an integer array nums of length n. Create an array ans of
 * length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n
 * (0-indexed).
 *
 * Specifically, ans is the concatenation of two nums arrays.
 *
 * Return the array ans.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> getConcatenation(vector<int> &nums) {
    int n = nums.size();
    vector<int> answer;
    for (int i = 0; i < 2 * n; ++i) {
      answer.push_back(nums[i % n]);
    }
    return answer;
  }
};

int main() {

  vector<int> example1 = {1, 4, 1, 2};
  vector<int> example2 = {22, 21, 20, 1};

  Solution solution;

  cout << "----- Example 1 -----" << endl;
  vector<int> answer1 = solution.getConcatenation(example1);
  for (const int &a : answer1)
    cout << a << endl;

  cout << "----- Example 2 -----" << endl;
  vector<int> answer2 = solution.getConcatenation(example2);
  for (const int &a : answer2)
    cout << a << endl;
}
