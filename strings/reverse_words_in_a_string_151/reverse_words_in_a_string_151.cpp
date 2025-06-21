/* 
 *  Given an input string s, reverse the order of the words.
 *
 *  A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
 *
 *  Return a string of the words in reverse order concatenated by a single space.
 *
 *  Note that s may contain leading or trailing spaces or multiple spaces between two words. 
 *  The returned string should only have a single space separating the words. Do not include any extra spaces.
 */

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Start by reversing the entire string — this places the words in the correct order but with characters reversed.
 * Then iterate through the string while tracking the start of each word using `j`.
 * When you reach a space or the end of the string, you've found the end of a word.
 * Reverse the characters from `j` to `i` to correct the word.
 * After fixing all words, remove leading and trailing spaces,
 * and use `std::unique` to remove duplicate spaces between words.
 * Return the cleaned string.
 */

class Solution {
  public:
    string reverseWords(string s) {
      int n = s.size();
      int j = 0;

      reverse(s.begin(), s.end());

      for (int i = 0; i < n + 1; i++) {
        if (s[i] == ' ' || i == n) {
          reverse(s.begin() + j, s.begin() + i);
          j = i + 1;
        }
      }

      s.erase(0, s.find_first_not_of(' '));
      s.erase(s.find_last_not_of(' ') + 1);

      auto new_end = unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
      s.erase(new_end, s.end());
      return s;
    }
};

int main() {

  string s = "the sky is blue";

  Solution solution;

  string reversedWords = solution.reverseWords(s);

  cout << reversedWords << endl;

  return 0;
}
