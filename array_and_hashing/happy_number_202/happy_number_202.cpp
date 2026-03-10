/*
 *  Write an algorithm to determine if a number n is happy.
 *
 *  A happy number is a number defined by the following process:
 *    - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *    - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *    - Those numbers for which this process ends in 1 are happy.
 *
 *  Return true if n is a happy number, and false if not.
 */

#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * Uses a set to detect cycles in the sequence of digit-square sums.
 *
 * 1. Initialize an unordered_set to store previously seen numbers.
 * 2. Define a lambda function `squareSum(int)` to compute the sum of squares of digits.
 * 3. Iterate while n is not 1 and hasn't been seen before:
 *    - Insert n into the set.
 *    - Update n to be the squareSum(n).
 * 4. Return true if n becomes 1 (happy number), false if a cycle is detected.
 */

class Solution {
  public:
    bool isHappy(int n) {

      unordered_set<int> seen;

      auto squares = [](int x) {
        int sum = 0;
        while (x > 0) {
          int d = x % 10;
          sum += d * d;
          x /= 10;
        }
        return sum;
      };

      while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = squares(n);
      }

      return n == 1;
    }
};

int main() {
  int n = 19;
  int m = 4;

  Solution solution;

  cout << "----- Example 1 -----" << endl;

  bool isHappyN = solution.isHappy(n);

  cout << isHappyN << endl;

  cout << "----- Example 2 -----" << endl;

  bool isHappyM = solution.isHappy(m);

  cout << isHappyM << endl;

  return 0;
}
