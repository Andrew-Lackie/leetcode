/*
 *  Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Initialize a frequency map from char to count.
 * - Iterate through each character in `s`, incrementing its count in the map.
 *
 * Iterate through each character in `t`:
 * - If the character does not exist in the map, return false.
 * - Otherwise, decrement its count.
 *
 * Finally, iterate through the frequency map:
 * - If any count is not zero, return false.
 *
 * If all checks pass, the strings are anagrams, so return true.
 */

class Solution {
  public:
    bool isAnagram(string s, string t) {
      unordered_map<char, int> freqMap;

      for (const char& c : s) freqMap[c]++;

      for (const char& c : t) {
        if (freqMap.count(c)) freqMap[c]--;
        else return false;
      }

      for (auto& [c, count] : freqMap) {
        if (count != 0) return false;
      }

      return true;
    }
};

int main() {

  string s = "anagram";
  string t = "nagaram";

  Solution solution;

  bool isAnagram = solution.isAnagram(s, t);

  cout << isAnagram << endl;

  return 0;
}
