/*
 *  There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
 *
 *  You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
 *  You begin the journey with an empty tank at one of the gas stations.
 *
 *  Given two integer arrays gas and cost, 
 *  return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
 *  otherwise return -1. If there exists a solution, it is guaranteed to be unique.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * Initialize two variables:
 *   - totalTank: the overall gas surplus across the entire trip
 *   - currTank: the current surplus while scanning from a candidate start point
 *
 * Iterate through each station:
 *   - Add gas[i] - cost[i] to both totalTank and currTank
 *   - If currTank drops below 0, it means we can't reach station i + 1 from the current start
 *     → Set start = i + 1
 *     → Reset currTank to 0
 *
 * After the loop:
 *   - If totalTank is >= 0, the circuit is possible, and the recorded start is valid
 *   - Otherwise, return -1 (the trip is impossible)
 */

class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int totalTank = 0;
      int currTank = 0;
      int start = 0;

      for (int i = 0; i < gas.size(); i++) {
        int diff = gas[i] - cost[i];
        totalTank += diff;
        currTank += diff;

        if (currTank < 0) {
          start = i + 1;
          currTank = 0;
        }
      }
      return totalTank >= 0 ? start : -1;
    }
};

int main() {
  vector<int> gas = {1, 2, 3, 4, 5};
  vector<int> cost = {3, 4, 5, 1, 2};

  Solution solution;

  int index = solution.canCompleteCircuit(gas, cost);

  cout << index << endl;
}
