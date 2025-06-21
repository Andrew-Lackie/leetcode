/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * For example, 2 is written as II in Roman numeral, just two ones added together. 
 * 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right. 
 * However, the numeral for four is not IIII. Instead, the number four is written as IV. 
 * Because the one is before the five we subtract it making four. 
 * The same principle applies to the number nine, which is written as IX. 
 * There are six instances where subtraction is used:
 *  * I can be placed before V (5) and X (10) to make 4 and 9. 
 *  * X can be placed before L (50) and C (100) to make 40 and 90. 
 *  * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 * Given a roman numeral, convert it to an integer.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Initialize an unordered_map to map each Roman numeral character to its corresponding integer value.
 * Iterate through the string s from left to right:
 *   - If the current value is less than the next value, subtract it from the total.
 *   - Otherwise, add it to the total.
 * After the loop, return the total.
 */

class Solution {
  public:
    int romanToInt(string s) {
      unordered_map<char, int> map = {
        {'I', 1 },
        {'V', 5 },
        {'X', 10 },
        {'L', 50 },
        {'C', 100 },
        {'D', 500 },
        {'M', 1000 },
      };

      int total = 0;

      for (int i = 0; i < s.size(); i++) {
        int curr = map[s[i]];
        char next = (i + 1) < s.size() ? s[i + 1] : '\0';

        if (curr < map[next]) {
          total -= curr;
        }
        else {
          total += curr;
        }
      }
      return total;
    }

    int romanToIntAlt(string s) {
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            char next = (i + 1 < s.size()) ? s[i + 1] : '\0';
            switch(s[i]) {
                case 'I':
                    if (next == 'V' || next == 'X') {
                        total -= 1;
                    }
                    else {
                        total += 1;
                    }
                    break;
                case 'X':
                    if (next == 'L' || next == 'C') {
                        total -= 10;
                    }
                    else {
                        total += 10;
                    }
                    break;
                case 'C':
                    if (next == 'D' || next == 'M') {
                        total -= 100;
                    }
                    else {
                        total += 100;
                    }
                    break;
                case 'V':
                    total += 5;
                    break;
                case 'L':
                    total += 50;
                    break;
                case 'D':
                    total += 500;
                    break;
                case 'M':
                    total += 1000;
            }
        }
        return total;
    }
};

int main() {
  string s = "MCMXCIV";

  Solution solution;

  int total = solution.romanToInt(s);

  cout << total << endl;

  return 0;
}

