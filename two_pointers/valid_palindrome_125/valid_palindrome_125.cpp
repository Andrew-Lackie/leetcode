/*
 *  A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
 *  it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 *
 *  Given a string s, return true if it is a palindrome, or false otherwise.
 */

#include <iostream>

using namespace std;

/*
 * To solve this, we use the two-pointer technique.
 * Initialize two pointers: i at the start (0) and j at the end (n - 1) of the string.
 * While i < j:
 *   - Skip non-alphanumeric characters by moving i forward or j backward as needed.
 *   - Compare the lowercase versions of the characters at i and j.
 *   - If they don't match, return false (not a palindrome).
 *   - If they match, move both pointers inward (i++, j--).
 * If the loop completes without mismatches, return true — the string is a valid palindrome.
 */

class Solution {
  public:
    bool isPalindrome(string s) {
      int n = s.size();
      int i = 0;
      int j = n - 1;

      while (j > i) {
        char first = s[i];
        char last = s[j];

        while (j > i && !isalnum(first)) first = s[++i];
        while (j > i && !isalnum(last)) last = s[--j];

        if (tolower(first) != tolower(last)) {
          return false;
        }
        i++;
        j--;
      }
      return true;
    }
};

int main() {
  string s = "A man, a plan, a canal: Panama";

  Solution solution;

  bool isPalindrome = solution.isPalindrome(s);

  return 0;
}

