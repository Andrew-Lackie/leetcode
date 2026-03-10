/*
 *  Implement the RandomizedSet class:
 *    - RandomizedSet() Initializes the RandomizedSet object.
 *    - bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
 *    - bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
 *    - int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
 *      Each element must have the same probability of being returned.
 *   
 *  You must implement the functions of the class such that each function works in average O(1) time complexity.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Initialize two private variables:
 *   - An unordered_map<int, int> to map each value to its index in the vector.
 *   - A vector<int> to store the actual values.
 *
 * The insert function checks if the value already exists:
 *   - If it does, return false.
 *   - Otherwise, append the value to the vector and record its index in the map.
 *
 * The remove function checks if the value exists:
 *   - If it does not, return false.
 *   - Otherwise:
 *       - Swap the element to be removed with the last element in the vector.
 *       - Update the index of the swapped value in the map.
 *       - Remove the last element from the vector.
 *       - Erase the removed value from the map.
 *
 * The getRandom function generates a random index and returns the value at that index in the vector.
 */

class RandomizedSet {
  private:
    unordered_map<int, int> valToIndex;
    vector<int> values;
  public:
    RandomizedSet() {}

    bool insert(int val) {
      if (valToIndex.count(val)) {
        return false;
      }

      values.push_back(val);
      valToIndex.insert({ val, values.size() - 1 });

      return true;
    }

    bool remove(int val) {
      if (!valToIndex.count(val)) {
        return false;
      }

      int back = values.back();
      int index = valToIndex[val];

      values[index] = back;
      valToIndex[back] = index;
      
      values.pop_back();
      valToIndex.erase(val);

      return true;
    }

    int getRandom() {
      return values[rand() % values.size()];
    }
};

int main() {
  RandomizedSet randomizedSet;

    cout << "[";
    cout << randomizedSet.insert(1) << ", ";
    cout << randomizedSet.remove(2) << ", ";
    cout << randomizedSet.insert(2) << ", ";
    cout << randomizedSet.getRandom() << ", ";
    cout << randomizedSet.remove(1) << ", ";
    cout << randomizedSet.insert(2) << ", ";
    cout << randomizedSet.getRandom();
    cout << "]" << endl;

  return 0;
}
