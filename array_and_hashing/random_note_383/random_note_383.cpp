/*
 *  Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 *  Each letter in magazine can only be used once in ransomNote.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * Initialize a frequency map to store the count of each character in the magazine.
 * Iterate through the ransom note:
 *  - If the character's frequency is 0 or it doesn't exist in the map, return false.
 *  - Otherwise, decrement the frequency count for that character.
 *
 * If the loop completes, all characters were available, so return true.
 */

class Solution {
  public: 
    bool canConstruct(string ransomNote, string magazine) {
      unordered_map<char, int> charMap;

      for (const char& c : magazine) {
        charMap[c]++;
      }
      
      for (const char& c : ransomNote) {
        if (charMap[c] == 0) return false;
        charMap[c]--;
      }
      return true;
    }
};

int main() {

  string ransomNote = "aa", magazine = "aab";

  Solution solution;

  bool canConstruct = solution.canConstruct(ransomNote, magazine);

  cout << canConstruct << endl;

  return 0;
}

