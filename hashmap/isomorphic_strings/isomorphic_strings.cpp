/*
 *  Given two strings s and t, determine if they are isomorphic.
 *
 *  Two strings s and t are isomorphic if the characters in s can be replaced to get t.
 *
 *  All occurrences of a character must be replaced with another character while preserving the order of characters. 
 *  No two characters may map to the same character, but a character may map to itself.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Because the problem requires a bijection (a one-to-one and onto mapping),
 * initialize two unordered_maps: one from s to t, and one from t to s.
 *
 * Iterate through each character in both strings:
 *   - If s[i] is already mapped and the mapping is not equal to t[i], return false.
 *   - If t[i] is already mapped and the mapping is not equal to s[i], return false.
 *   - Otherwise, store the mapping from s[i] to t[i] and from t[i] to s[i].
 *
 * If the loop completes without conflict, then the strings are isomorphic, so return true.
 */

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char, char> sTMap;
      unordered_map<char, char> tSMap;

      for (int i = 0; i < s.size(); i++) {
        if (sTMap.count(s[i]) && sTMap[i] != t[i]) return false;
        if (tSMap.count(t[i]) && tSMap[i] != s[i]) return false;
        tSMap[i] = s[i];
        sTMap[i] = t[i];
      }

      return true;
    }
};

int main() {
  string s = "egg", t = "add";

  Solution solution;

  bool isIsomorphic = solution.isIsomorphic(s, t);

  cout << isIsomorphic << endl;

  return 0;
}
