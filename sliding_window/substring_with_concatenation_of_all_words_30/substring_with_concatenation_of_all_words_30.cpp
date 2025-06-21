/*
 *  You are given a string s and an array of strings words. All the strings of words are of the same length.
 *
 *  A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
 *    - For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. 
 *      "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
 *
 *  Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Initialize a frequency map by iterating over the input words and counting each occurrence.
 *
 * Loop from i = 0 to wordLen - 1. This allows us to scan the string from every possible word-aligned offset.
 *
 * For each offset:
 *   - Initialize a `seen` map to count how many times each word has appeared in the current window.
 *   - Set `left` to i (start of the window) and `total` to 0 (total words matched so far).
 *
 *   Inside this loop, slide the window by wordLen each step:
 *     - Extract the substring of length `wordLen` starting at `right`.
 *     - If the word exists in the frequency map:
 *         - Increment its count in `seen` and increment `total`.
 *         - While `seen[word]` exceeds its allowed frequency:
 *             - Decrement the count of the word at the left of the window
 *             - Move `left` forward by `wordLen` and decrement `total`
 *         - If `total == words.size()`, we found a valid substring → push `left` to the result.
 *     - If the word is not in the frequency map:
 *         - Clear `seen`, reset `total` to 0, and move `left` to `right + wordLen`.
 *
 * Finally, return the result indices.
 */

class Solution {
  public:
    vector<int> findSubstring(string s, vector<string>& words) {
      unordered_map<string, int> freqMap;
      vector<int> indices;

      for (const string& word : words) {
        freqMap[word] += 1;
      }

      int wordLen = words[0].size();
      int wordArrLen = words.size();
      int strLen = s.size();
      int substringLen = wordLen * wordArrLen;

      for (int i = 0; i < wordLen; i++) {
        unordered_map<string, int> seenMap;
        int left = 0, total = 0;

        for (int right = i; right + wordLen <= strLen; right += wordLen) {
          string word = s.substr(right, wordLen);

          if (freqMap.count(word)) {
            seenMap[word]++;
            total++;

            while (seenMap[word] > freqMap[word]) {
              seenMap[s.substr(left, wordLen)]--;
              left += wordLen;
              total--;
            }

            if (total == wordArrLen) {
              indices.push_back(left);
            }
          }
          else {
            seenMap.clear();
            total = 0;
            left = right + wordLen;
          }
        }
      }

      return indices;
    }
};

int main() {
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};

  Solution solution;

  vector<int> indices = solution.findSubstring(s, words);

  for (const int& i : indices) {
    cout << i << endl;
  }
}
