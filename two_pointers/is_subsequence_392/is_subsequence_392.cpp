/*
 *  Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 *
 *  A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
 *  of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 */

#include <iostream>

using namespace std;

/*
 * Initialize a pointer j = 0 to track the position in the subsequence string s.
 * Iterate through the string t using a for loop while j is less than the size of s.
 *   - If s[j] == t[i], increment j (we found the next character in the subsequence).
 * After the loop, return j == s.size().
 *   - If true, all characters in s were found in order within t (s is a subsequence).
 *   - If false, not all characters in s were matched (s is not a subsequence).
 */

class Solution {
  public:
    bool isSubsequence(string s, string t) {
      int n = t.size();
      int m = s.size();

      int j = 0;
      for (int i = 0; i < n && j < m; i++)  {
        if (t[i] == s[j]) j++;
      }

      return j == m;
    }
};

int main() {
  string s = "abc";
  string t = "ahbgdc";

  Solution solution;

  bool isSubsequence = solution.isSubsequence(s, t);

  cout << isSubsequence << endl;

  return 0;
}
