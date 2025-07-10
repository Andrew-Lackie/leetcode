/*
 *  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 *  Implement the MinStack class:
 *
 *    - MinStack() initializes the stack object.
 *    - void push(int val) pushes the element val onto the stack.
 *    - void pop() removes the element on the top of the stack.
 *    - int top() gets the top element of the stack.
 *    - int getMin() retrieves the minimum element in the stack.
 *
 *  You must implement a solution with O(1) time complexity for each function.
 */

#include <iostream>
#include <stack>

using namespace std;

/*
 *  Use a stack of pairs <int, int>, where:
 *    - The first element is the actual value being pushed.
 *    - The second element is the minimum value in the stack at that point.
 *
 *  push(val):
 *    - If the stack is empty, then the minimum is val; push {val, val}.
 *    - Otherwise, compare val with the current min (top().second), and push {val, min(val, top().second)}.
 *
 *  pop():
 *    - Remove the top element of the stack.
 *
 *  top():
 *    - Return the first value of the top pair (top().first).
 *
 *  getMin():
 *    - Return the second value of the top pair (top().second).
 */

class MinStack {
  private:
    stack<pair<int,int>> st;
  public:
    MinStack() {}

    void push(int val) {
      if (st.empty()) st.push({ val, val });
      else {
        st.push({ val, min(st.top().second, val) });
      }
    }

    void pop() {
      st.pop();
    }

    int top() {
      return st.top().first;
    }

    int getMin() {
      return st.top().second;
    }
};

int main() {
  MinStack minStack;

  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;
  minStack.pop();
  cout << minStack.top() << endl;
  cout << minStack.getMin() << endl;

  return 0;
}
