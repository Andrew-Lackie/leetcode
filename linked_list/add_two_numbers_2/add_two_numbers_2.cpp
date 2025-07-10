/*
 *  You are given two non-empty linked lists representing two non-negative integers. 
 *  The digits are stored in reverse order, and each of their nodes contains a single digit. 
 *  Add the two numbers and return the sum as a linked list.
 *
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 *  Initialize a dummy head node to simplify list construction and a pointer `curr` to track the current position.
 *  Initialize an integer `carry` to 0 to hold the carry-over from each digit-wise addition.
 *
 *  Loop while at least one of the following is true: `l1` is not null, `l2` is not null, or `carry` is non-zero:
 *    - Set `sum` to the current value of `carry`.
 *    - If `l1` exists, add its value to `sum` and move `l1` to `l1->next`.
 *    - If `l2` exists, add its value to `sum` and move `l2` to `l2->next`.
 *    - Update `carry` as `sum / 10` and the current digit as `sum % 10`.
 *    - Create a new node with the digit value and link it to `curr->next`.
 *    - Advance `curr` to `curr->next`.
 *
 *  After the loop, return `dummy->next` — the head of the resulting linked list.
 */

class Solution {
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;

      int carry = 0;

      while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
          sum += l1->val;
          l1 = l1->next;
        }

        if (l2) {
          sum += l2->val;
          l2 = l2->next;
        }
 
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
      }

      return dummy->next;
    }
};

int main() {
  cout << "----- Example 1 -----" << endl;

  ListNode* a1 = new ListNode(2);
  ListNode* a2 = new ListNode(4);
  ListNode* a3 = new ListNode(3);

  a1->next = a2;
  a2->next = a3;
 
  ListNode* b1 = new ListNode(5);
  ListNode* b2 = new ListNode(6);
  ListNode* b3 = new ListNode(4);

  b1->next = b2;
  b2->next = b3;

  Solution solution;

  ListNode* sum1 = solution.addTwoNumbers(a1, b1);

  while (sum1 != nullptr) {
    cout << sum1->val << ' ';
    sum1 = sum1->next;
  }

  cout << endl;

  cout << "----- Example 2 -----" << endl;

  ListNode* c1 = new ListNode(9);
  ListNode* c2 = new ListNode(9);
  ListNode* c3 = new ListNode(9);
  ListNode* c4 = new ListNode(9);
  ListNode* c5 = new ListNode(9);
  ListNode* c6 = new ListNode(9);
  ListNode* c7 = new ListNode(9);

  c1->next = c2;
  c2->next = c3;
  c3->next = c4;
  c4->next = c5;
  c5->next = c6;
  c6->next = c7;

  ListNode* d1 = new ListNode(9);
  ListNode* d2 = new ListNode(9);
  ListNode* d3 = new ListNode(9);
  ListNode* d4 = new ListNode(9);

  d1->next = d2;
  d2->next = d3;
  d3->next = d4;

  ListNode* sum2 = solution.addTwoNumbers(c1, d1);

  while (sum2 != nullptr) {
    cout << sum2->val << ' ';
    sum2 = sum2->next;
  }

  cout << endl;

  return 0;
}

