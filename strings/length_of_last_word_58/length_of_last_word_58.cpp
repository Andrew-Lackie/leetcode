/*
 *  Given a string s consisting of words and spaces, return the length of the last word in the string.
 *
 *  A word is a maximal substring consisting of non-space characters only.
 */

#include <iostream>

using namespace std;

/*
 * Initialize count to 0.
 * Iterate through the string s from the end:
 *   - If the current character is not a space, increment count.
 *   - If it is a space and count > 0, return count (we've already counted the last word).
 * After the loop, return count (handles case where string has only one word with no trailing spaces).
 */

class Solution {
  public: 
    int lengthOfLastWord(string s) {
      int count = 0;
      for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != ' ') {
          count++;
        }
        else if (count > 0) return count;
      }
      return count;
    }
};

int main() {

  string s = "  fly me   to   the moon  ";

  Solution solution;

  int count = solution.lengthOfLastWord(s);

  cout << count << endl;

  return 0;
}
