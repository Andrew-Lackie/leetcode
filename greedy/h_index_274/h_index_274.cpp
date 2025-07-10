/*
 * Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
 * The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Sort the citations array in descending order.
 * Iterate through the array:
 *  - At index i, if citations[i] < i + 1, return i as the h-index.
 *  - If all citations[i] ≥ i + 1, return the length of the array (n).
 */

class Solution {
  public:
    int hIndex(vector<int>& citations) {
      int n = citations.size();
      sort(citations.begin(), citations.end(), greater<int>());
      for (int i = 0; i < n; i++) {
        if (citations[i] < i + 1) {
          return i;
        }
      }
      return n;
    }
};

int main() {

  vector<int> citations = {3, 0, 6, 1, 5};

  Solution solution;

  int hIndex = solution.hIndex(citations);

  cout << hIndex << endl;

  return 0;
}


