/*
 *  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <iostream>

using namespace std;

/*
 * Iterate through each character in the haystack using a for loop.
 * At each index i, use a while loop to compare characters from haystack[i + j] and needle[j].
 * If the characters match, increment j.
 * If j reaches the length of the needle, a full match has been found — return i.
 * If characters mismatch or bounds are exceeded, reset j and continue to the next i.
 */

class Solution {
  public:
    int strStr(string haystack, string needle) {
      int n = haystack.size(), m = needle.size();

      int j = 0;

      for (int i = 0; i <= n - m; i++) {
        j = 0;
        while (i + j < n && haystack[i + j] == needle[j]) j++;
        if (j == m) return i;
      }

      return -1;
    }
};

int main() {
  string haystack = "sadbutsad";
  string needle = "sad";

  Solution solution;

  int index = solution.strStr(haystack, needle);

  cout << index << endl;

  return 0;
}
