/*
 *  Given a string s, find the length of the longest substring without duplicate characters.
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
      int left = 0, right = 0;
      int maxLen = 0;

      unordered_set<char> seen;

      while (right < n) {
        if (seen.count(s[right])) {
          seen.erase(s[left++]);
        }
        else {
          maxLen = max(maxLen, right - left + 1);
          seen.insert(s[right++]);
        }
      }
      return maxLen;
    }
};

int main() {
  string s = "abcabcbb";

  Solution solution;

  int maxLen = solution.lengthOfLongestSubstring(s);

  cout << maxLen << endl;

  return 0;
}

