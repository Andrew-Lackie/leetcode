/*
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize maxProfit to 0 and minPrice to the first element in prices.
 * Iterate through the array starting from index 1:
 *   - If prices[i] is less than minPrice, update minPrice.
 *   - Otherwise, calculate the profit by selling at prices[i],
 *     and update maxProfit if this profit is greater.
 * Return maxProfit at the end.
 */

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int maxProfit = 0;
      int minPrice = prices[0];

      for (int i = 0; i < n; i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        maxProfit = max(maxProfit, prices[i] - minPrice);
      }

      return maxProfit;
    }
};

int main() {

  vector<int> prices = {7, 1, 5, 3, 6, 4};

  Solution solution;

  int maxProfit = solution.maxProfit(prices);

  cout << maxProfit << endl;

  return 0;
}
