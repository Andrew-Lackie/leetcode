/*
 *  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 *
 *  On each day, you may decide to buy and/or sell the stock. 
 *  You can only hold at most one share of the stock at any time. 
 *  However, you can buy it then immediately sell it on the same day.
 *
 *  Find and return the maximum profit you can achieve.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize total to 0.
 * Iterate through prices starting from index 1:
 *   - If the current price is greater than the previous day's price,
 *     add the difference (prices[i] - prices[i - 1]) to total.
 * This captures all profitable upward moves.
 * Return total at the end.
 */

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int total = 0;

      for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
          total += prices[i] - prices[i - 1];
        }
      }
      return total;
    }
};

int main() {

  vector<int> prices = {7, 1, 5, 3, 6, 4};

  Solution solution;

  int maxProfit = solution.maxProfit(prices);

  cout << maxProfit << endl;

  return 0;
}

