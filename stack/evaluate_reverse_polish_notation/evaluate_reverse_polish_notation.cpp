/*
 *  You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
 *
 *  Evaluate the expression. Return an integer that represents the value of the expression.
 *
 *  Note that:
 *
 *    - The valid operators are '+', '-', '*', and '/'.
 *    - Each operand may be an integer or another expression.
 *    - The division between two integers always truncates toward zero.
 *    - There will not be any division by zero.
 *    - The input represents a valid arithmetic expression in a reverse polish notation.
 *    - The answer and all the intermediate calculations can be represented in a 32-bit integer.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

/*
 * Initialize a set `operators` containing the four valid operator strings: "+", "-", "*", "/".
 * Initialize a stack of integers to store operands.
 *
 * Iterate through each token in the input vector:
 *   - If the token is not in `operators`, it is an operand:
 *       - Convert the token to an integer using `stoi` and push it onto the stack.
 *
 *   - If the token is an operator:
 *       - Pop the top two operands from the stack:
 *           - The first popped value is the second operand (`a`)
 *           - The second popped value is the first operand (`b`)
 *       - Apply the operator to `b` and `a` (i.e., `b op a`), and push the result back onto the stack.
 *
 * After processing all tokens, the result will be the only value remaining in the stack.
 * Return that value.
 */

class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      unordered_set<string> operators = {"+", "-", "*", "/"};
      stack<int> st;

      for (string& token : tokens) {
        if (!operators.count(token)) st.push(stoi(token));
        else {
          int b = st.top(); st.pop();
          int a = st.top(); st.pop();
            if (token == "+") st.push(b + a);
            else if (token == "-") st.push(b - a);
            else if (token == "*") st.push(b * a);
            else if (token == "/") st.push(b / a);
        }
      }
      return st.top();
    }
};

int main() {
  vector<string> tokens = {"2", "1", "+", "3", "*"};

  Solution solution;

  int answer = solution.evalRPN(tokens);

  cout << answer << endl;

  return 0;
}



