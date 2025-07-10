/*
 *  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 *  An input string is valid if:
 *
 *  1. Open brackets must be closed by the same type of brackets.
 *  2. Open brackets must be closed in the correct order.
 *  3. Every close bracket has a corresponding open bracket of the same type.
 */

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

/*
 *  Initialize a map from closing brackets to their corresponding opening brackets,
 *  and a stack to keep track of opening brackets as they appear.
 *
 *  Iterate through each character in the string:
 *    - If the character is not in the map, it's an opening bracket — push it onto the stack.
 *    - If it is a closing bracket:
 *        - If the stack is empty, it's invalid (no opening bracket to match it).
 *        - If the top of the stack doesn't match the expected opening bracket, it's a mismatch — return false.
 *        - Otherwise, it's a valid match — pop the top element off the stack.
 *
 *  After the loop, if the stack is empty, all brackets were matched — return true.
 *  If not, some opening brackets were unmatched — return false.
 */

class Solution {
  public:
    bool isValid(string s) {
      unordered_map<char, char> mp = {
        { '}', '{' },
        { ']', '[' },
        { ')', '(' }
      };

      stack<char> st;

      for (char& c : s) {
        if (!mp.count(c)) st.push(c);
        else {
          if (st.empty() || st.top() != mp[c]) return false;
          st.pop();
        }
      }

      return st.empty();
    }
};

int main() {

  Solution solution;

  cout << "----- Example 1 -----" << endl;
  string s1 = "()";
  bool isValid1 = solution.isValid(s1);
  cout << isValid1 << endl;

  cout << "----- Example 2 -----" << endl;
  string s2 = "()[]{}";
  bool isValid2 = solution.isValid(s2);
  cout << isValid2 << endl;

  cout << "----- Example 3 -----" << endl;
  string s3 = "(]";
  bool isValid3 = solution.isValid(s3);
  cout << isValid3 << endl;

  cout << "----- Example 4 -----" << endl;
  string s4 = "([])";
  bool isValid4 = solution.isValid(s4);
  cout << isValid4 << endl;


  return 0;
}


