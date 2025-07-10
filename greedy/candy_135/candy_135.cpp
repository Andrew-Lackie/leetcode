/*
 *  There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
 *
 *  You are giving candies to these children subjected to the following requirements:
 *    * Each child must have at least one candy.
 *    * Children with a higher rating get more candies than their neighbors.
 *
 *  Return the minimum number of candies you need to have to distribute the candies to the children.
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * Initialize a new vector `answer` of size `ratings.size()` with all elements set to 1.
 *
 * First pass (left to right):
 *   - Iterate from index 1 to n - 1.
 *   - If ratings[i] > ratings[i - 1], then set answer[i] = answer[i - 1] + 1.
 *
 * Second pass (right to left):
 *   - Iterate from index n - 2 to 0.
 *   - If ratings[i] > ratings[i + 1], then set answer[i] = max(answer[i], answer[i + 1] + 1).
 *
 * Finally, return the sum of all elements in the answer vector.
 */

class Solution {
  public: 
    int candy(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> answer(n, 1);

      for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
          answer[i] = answer[i - 1] + 1;
        }
      }

      for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
          answer[i] = max(answer[i], answer[i + 1] + 1);
        }
      }

      return accumulate(answer.begin(), answer.end(), 0);
    }
};

int main() {

  vector<int> ratings = {1, 0, 2};

  Solution solution;

  int minimum = solution.candy(ratings);

  cout << minimum << endl;

  return 0;
}



