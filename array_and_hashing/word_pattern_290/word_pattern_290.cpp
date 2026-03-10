/*
 *  Given a pattern and a string s, find if s follows the same pattern.
 *
 *  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
 *    - Each letter in pattern maps to exactly one unique word in s.
 *    - Each unique word in s maps to exactly one letter in pattern.
 *    - No two letters map to the same word, and no two words map to the same letter.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
 * Initialize a vector<string> to store the words from `s`:
 *   - Use a pointer `j` to track the start of each word.
 *   - Iterate through `s`; when you encounter a space or reach the end, 
 *     extract the substring from `j` to `i` and push it into the vector.
 *
 * If the number of words does not match the length of `pattern`, 
 * return false — the mapping cannot be one-to-one and onto.
 *
 * Initialize two unordered_maps:
 *   - One mapping characters in `pattern` to words in `s`.
 *   - One mapping words in `s` to characters in `pattern`.
 *
 * For each index `i` in the `pattern`:
 *   - If the character is already mapped, check it maps to the current word. If not, return false.
 *   - If the word is already mapped, check it maps to the current character. If not, return false.
 *   - Otherwise, record both mappings.
 *
 * If the loop completes without conflict, return true.
 */

class Solution {
  public:
    bool wordPattern(string pattern, string s) {
      int strLen = s.size();
      vector<string> words;

      int j = 0;
      for (int i = 0; i <= strLen; i++) {
        const char& c = s[i];
        if (c == ' ' || i == strLen) {
          words.push_back(s.substr(j, i - j));
          j = i + 1;
        }
      }

      if (words.size() != pattern.size()) return false;

      unordered_map<char, string> patternMap;
      unordered_map<string, char> wordsMap;

      for (int i = 0; i < words.size(); i++) {
        if (patternMap.count(pattern[i]) && patternMap[pattern[i]] != words[i]) return false;
        if (wordsMap.count(words[i]) && wordsMap[words[i]] != pattern[i]) return false;
        wordsMap[words[i]] = pattern[i];
        patternMap[pattern[i]] = words[i];
      }

      return true;
    }
};

int main() {
  string pattern = "abba", s = "dog cat cat dog";

  Solution solution;

  bool wordPattern = solution.wordPattern(pattern, s);

  cout << wordPattern << endl;

  return 0;
}
