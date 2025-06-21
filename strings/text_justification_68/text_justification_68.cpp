/*
 *  Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
 *
 *  You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
 *  Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
 *
 *  Extra spaces between words should be distributed as evenly as possible. 
 *  If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 *  For the last line of text, it should be left-justified, and no extra space is inserted between words.
 *
 *  Note:
 *   - A word is defined as a character sequence consisting of non-space characters only.
 *   - Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 *   - The input array words contains at least one word.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * fullJustify:
 *  Initialize two string vectors: `currLine` to hold the current line of words, and `lines` to hold the final output. 
 *  Also initialize an integer `currLength` to track the total character count (excluding spaces).
 *
 *  Iterate through each word in the input:
 *    - If the total length of the current line (`currLength`), plus the size of the next word, plus the number of spaces between words (`currLine.size()`), exceeds `maxWidth`:
 *        - Justify the current line using `justify(...)` and push the result to `lines`.
 *        - Clear `currLine` and reset `currLength`.
 *    - Otherwise, add the word to `currLine` and increase `currLength` by the length of the word.
 *
 *  After the loop ends, handle the final line with `leftJustify(...)` since it should be left-aligned.
 *  Return `lines`.
 *
 * justify:
 *  This function takes a vector of words, the total character length of those words (`length`), and the maximum width.
 *  - If there is only one word, return it left-aligned with spaces padded to the right.
 *  - Otherwise:
 *      - Calculate the total number of gaps between words: `gaps = words.size() - 1`.
 *      - Calculate the total number of spaces to distribute: `totalSpaces = maxWidth - length`.
 *      - Determine base space width per gap: `evenSpace = totalSpaces / gaps`, and the number of gaps that get one extra space: `extraSpace = totalSpaces % gaps`.
 *      - For each word in the line:
 *          - Append the word to the result.
 *          - If it is not the last word, append `evenSpace` spaces, and one extra if `i < extraSpace`.
 *  Return the result.
 *
 * leftJustify:
 *  This function takes a vector of words and the max width.
 *  - Append each word to the result.
 *  - Add a space between each word (except after the last).
 *  - Pad the end of the result with spaces until it reaches `maxWidth`.
 *  Return the result.
 */

class Solution {
  private:
    string justify(vector<string>& words, int length, int maxWidth) {
      int gaps = words.size() - 1;
      string result;

      if (gaps == 0) {
        result = words[0] + string(maxWidth - length, ' ');
        return result;
      }

      int totalSpaces = maxWidth - length;
      int evenSpace = totalSpaces / gaps;
      int extraSpace = totalSpaces % gaps;

      for (int i = 0; i < words.size(); i++) {
        result += words[i];

        if (i < gaps) {
          int spaces = evenSpace + (i < extraSpace ? 1 : 0);
          result += string(spaces, ' ');
        }
      }

      return result;
    }

    string leftJustify(const vector<string>& words, int maxWidth) {
      string result;

      for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += ' ';
      }

      result += string(maxWidth - result.size(), ' ');
      return result;
    }
 
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> lines;
      vector<string> currLine;

      int currLength = 0;

      for (const string& word : words) {
        if (currLength + currLine.size() + word.size() > maxWidth) {
          lines.push_back(justify(currLine, currLength, maxWidth));
          currLine.clear();
          currLength = 0;
        }
        currLine.push_back(word);
        currLength += word.size();
      }
      lines.push_back(leftJustify(currLine, maxWidth));
      return lines;
    }
};

int main() {
  vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
  int maxWidth = 16;

  Solution solution;

  vector<string> result = solution.fullJustify(words, maxWidth);

  for (const string& words : result) {
    cout << words << endl;
  }

  return 0;
}
