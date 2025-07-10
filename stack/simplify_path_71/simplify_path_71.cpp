/*
 *  You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.
 *
 *  The rules of a Unix-style file system are as follows:
 *
 *    - A single period '.' represents the current directory.
 *    - A double period '..' represents the previous/parent directory.
 *    - Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
 *    - Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
 *
 *  The simplified canonical path should follow these rules:
 *
 *    - The path must start with a single slash '/'.
 *    - Directories within the path must be separated by exactly one slash '/'.
 *    - The path must not end with a slash '/', unless it is the root directory.
 *    - The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
 *
 *  Return the simplified canonical path.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    string simplifyPath(string path) {
      stack<string> st;
      auto split = [](string str) {
        vector<string> tokens;
        stringstream ss(str);
        string token;

        while (getline(ss, token, '/')) {
          if (!token.empty()) tokens.push_back(token);
        }
        return tokens;
      };

      vector<string> tokens = split(path);

      for (const string& token : tokens) {
        if (token == "" || token == ".") continue;
        else if (token == ".." && !st.empty()) st.pop();
        else st.push(token);
      }

      vector<string> directories;

      while (!st.empty()) {
        directories.push_back(st.top());
        st.pop();
      }

      reverse(directories.begin(), directories.end());

      string canonical = "/";

      for (int i = 0; i < directories.size(); i++) {
        canonical += directories[i];
        if (i != directories.size() - 1) canonical += "/";
      }

      return canonical;
    }
};

int main() {
  Solution solution;

  cout << "----- Example 1 -----" << endl;;
  string path1 = "/home/";
  string answer1 = solution.simplifyPath(path1);
  cout << answer1 << endl;

  cout << "----- Example 2 -----" << endl;;
  string path2 = "/home//foo/";
  string answer2 = solution.simplifyPath(path2);
  cout << answer2 << endl;

  cout << "----- Example 3 -----" << endl;;
  string path3 = "/home/user/Documents/../Pictures";
  string answer3 = solution.simplifyPath(path3);
  cout << answer3 << endl;

  return 0;
}
