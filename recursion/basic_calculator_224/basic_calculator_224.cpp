/*
 *  Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
 *
 *  Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 */

#include <iostream>

using namespace std;

/*
 * To solve this using recursion, initialize an index `i` to track the position in the string,
 * and call a helper function `parse`, passing the string and index by reference.
 *
 * In `parse`, initialize:
 *  - `num` to build the current number,
 *  - `result` to accumulate the running total,
 *  - `sign` to track whether the current number is positive or negative.
 *
 * Use a while loop that continues until the end of the string or a closing parenthesis:
 *  - If the character is a digit, update `num = num * 10 + (c - '0')` to build multi-digit numbers.
 *  - If the character is '+' or '-', apply the previous number to `result` using `sign`,
 *    then update `sign` to the new operator and reset `num` to 0.
 *  - If the character is '(', increment `i`, recursively call `parse`, and assign the returned value to `num`.
 *  - If the character is ')', apply the final `sign * num` to `result`, increment `i`, and return `result`.
 *
 * After the loop, apply the last `sign * num` to `result` and return it.
 */

class Solution {
  public:
    int calculate(string s) {
      int i = 0;
      return parse(s, i);
    }

  private:
    int parse(string& s, int& i) {
      int num = 0, result = 0, sign = 1;

      while (i < s.size()) {
        char c = s[i];
        if (isdigit(c)) {
          num = num * 10 + (c - '0');
        }
        else if (c == '+') {
          result += sign * num;
          sign = 1;
          num = 0;
        }
        else if (c == '-') {
          result += sign * num;
          sign = -1;
          num = 0;
        }
        else if (c == '(') {
          i++;
          num = parse(s, i);
        }
        else if (c == ')') {
          result += sign * num;
          return result;
        }
        i++;
      }
      result += sign * num;
      return result;
    }
};

int main() {
  string s = "(1+(4+5+2)-3)+(6+8)";

  Solution solution;

  int num = solution.calculate(s);

  cout << num << endl;

  return 0;
}
