/*
 *  Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. 
 *  If there is no such substring, return the empty string "".
 *
 *  The testcases will be generated such that the answer is unique.
 */

#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

/*
 * Build a frequency map `need` from string `t`, tracking how many of each character are required.
 *
 * Initialize a second map `window` to track the count of characters in the current window of `s`.
 *
 * Use two pointers `left` and `right` to define the current window in `s`.
 *
 * Also initialize:
 *   - `have`: the number of characters that currently meet the required frequency.
 *   - `needCount`: total number of unique characters required (size of `need` map).
 *   - `minLen`: the length of the smallest valid window found (start with INT_MAX).
 *   - `minStart`: the start index of that minimum window.
 *
 * Begin expanding the window with `right`:
 *   - For each character at `s[right]`, increment its count in `window`.
 *   - If that character is in `need` and its count in `window` equals its required count in `need`,
 *     then increment `have`.
 *
 * When `have == needCount`, the window is valid:
 *   - Check if the current window is smaller than `minLen`; if so, update `minLen` and `minStart`.
 *   - Try to shrink the window by incrementing `left`:
 *     - For the character at `s[left]`, if it is in `need` and `window[c] == need[c]`, decrement `have`.
 *     - Then decrement `window[c]` and increment `left`.
 *
 * Continue this process until `right` reaches the end of `s`.
 *
 * After the loop:
 *   - If `minLen` was updated (not still INT_MAX), return the substring from `minStart` with length `minLen`.
 *   - Otherwise, return an empty string.
 */

class Solution {
  public:
    string minWindow(string s, string t) {
      unordered_map<char, int> need;
      unordered_map<char, int> window;

      for (const char& c : t) need[c]++;

      int left = 0, right = 0;
      int needCount = t.size(), have = 0;
      int minStart = 0, minLen = INT_MAX;

      while (right < s.size()) {
        char& c = s[right];
        window[c]++;

        if (need.count(c) && need[c] == window[c]) have++;

        while (have == needCount) {
          if (right - left + 1 < minLen) {
            minLen = right - left + 1;
            minStart = left;
          }

          char& leftChar = s[left];

          if (need.count(leftChar) && window[leftChar] == need[leftChar]) have--;
          window[leftChar]--;
          left++;
        }
        right++;
      }
      return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main() {
  string s = "ADOBECODEBANC";
  string t = "ABC";

  Solution solution;

  string minWindow = solution.minWindow(s, t);

  cout << minWindow << endl;

  return 0;
}
