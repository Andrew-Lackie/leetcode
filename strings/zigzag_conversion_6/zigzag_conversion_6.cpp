/*
 *  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 *  And then read line by line: "PAHNAPLSIIGYIR"
 *  
 *  Write the code that will take a string and make this conversion given a number of rows:
 *
 *  string convert(string s, int numRows);
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * If numRows is 1 or greater than or equal to the length of s, return s (no zigzag needed).
 *
 * Initialize a vector of strings with size numRows — each element represents a row in the zigzag pattern.
 * Use a variable currRow to track the current row index, and a boolean goingDown to indicate direction.
 *
 * Iterate through each character in s:
 *   - Append the character to rows[currRow]
 *   - If currRow is 0 or numRows - 1, reverse direction by flipping goingDown
 *   - Update currRow: increment if goingDown is true, otherwise decrement
 *
 * After filling all rows, concatenate them using accumulate and return the final result.
 */

class Solution {
  public:
    string convert(string s, int numRows) {
      int n = s.size();
      if (numRows == 1 || numRows >= n) return s;

      vector<string> rows(numRows, "");
      int currRow = 0;
      bool goingDown = false;

      for (int i = 0; i < n; i++) {
        rows[currRow] += s[i];

        if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
        currRow += goingDown ? 1 : -1;
      }

      return accumulate(rows.begin(), rows.end(), string{});
    }
};

int main() {
  string s = "PAYPALISHIRING";

  Solution solution;

  string zigzag = solution.convert(s, 3);

  cout << zigzag << endl;

  return 0;
}
