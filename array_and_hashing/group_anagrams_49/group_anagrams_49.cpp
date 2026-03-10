/*
 *  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
 * Create an unordered_map<string, vector<string>> to group anagrams.
 *
 * For each string in strs:
 *   - Copy the string and sort it alphabetically to form a key.
 *   - Use the sorted key to insert the original string into the corresponding group in the map.
 *
 * After processing all strings, iterate through the map:
 *   - Push each group (vector<string>) into the final result vector.
 *
 * Return the result vector of grouped anagrams.
 */

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> strMap;
      vector<vector<string>> anagrams;

      for (const string& str : strs) {
        string key = str;
        sort(key.begin(), key.end());
        strMap[key].push_back(str);
      }

      for (auto& [_, vec] : strMap) anagrams.push_back(vec);

      return anagrams;
    }
};

int main() {

  vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

  Solution solution;

  vector<vector<string>> groupAnagrams = solution.groupAnagrams(strs);

  for (const vector<string>& group : groupAnagrams) {
    for (const string& anagram : group) {
      cout << anagram << '\t';
    }
    cout << endl;
  }

  return 0;
}
