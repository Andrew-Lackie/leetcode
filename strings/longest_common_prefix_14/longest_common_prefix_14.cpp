/*
 *  Write a function to find the longest common prefix string amongst an array of strings.
 *  If there is no common prefix, return an empty string "".
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * To find the longest common prefix among all strings:
 *
 * - Use a while loop to iterate through character positions (index i).
 * - At each position, compare the character at that index in every string.
 *   - Use a for loop to iterate through the strings.
 *   - If any string is shorter than i or has a different character at index i, stop.
 * - If all strings have the same character at index i, append it to the result.
 *
 * Return the accumulated prefix after exiting the loop.
 */

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      string longest = "";
      bool condition = true;
      int i = 0;
      while (condition) {
        if (i >= strs[0].size()) break;
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
          if (strs[j][i] != c) {
            condition = false;
          }
        }
        if (condition) longest += c;
        i++;
      }
      return longest;
    }
};

int main() {

  vector<string> strs = {"flower", "flow", "flight"};

  Solution solution;

  string longest = solution.longestCommonPrefix(strs);

  cout << longest << endl;

  return 0;
}


