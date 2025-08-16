/*
 *  Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 *
 *  You should preserve the original relative order of the nodes in each of the two partitions.
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>

using namespace std;

/*
 * 1. Initialize two dummy nodes: `before` and `after`.
 *    - These will anchor two separate lists:
 *      - One for nodes with values < x
 *      - One for nodes with values >= x
 *
 * 2. Use two pointers: `bIterator` and `aIterator` to build the two lists.
 *
 * 3. Iterate through the original list:
 *    - If `head->val < x`, append the node to the 'before' list.
 *    - Otherwise, append it to the 'after' list.
 *    - Move `head` forward each time.
 *
 * 4. After traversal:
 *    - Terminate the 'after' list by setting `aIterator->next = nullptr`.
 *    - Link the 'before' list to the head of the 'after' list:
 *      `bIterator->next = after->next`.
 *
 * 5. Return `before->next` as the new list head.
 */

class Solution {
  public:
    ListNode* partition(ListNode* head, int x) {
      ListNode* before = new ListNode(0);
      ListNode* bIterator = before;

      ListNode* after = new ListNode(0);
      ListNode* aIterator = after;

      while (head) {
        if (head->val < x) {
          bIterator->next = head;
          bIterator = bIterator->next;
        }
        else {
          aIterator->next = head;
          aIterator = aIterator->next;
        }
        head = head->next;
      }

      bIterator->next = after->next;
      aIterator->next = nullptr;

      return before->next;
    }
};

int main() {

  int k = 3;

  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(4);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(2);
  ListNode* n5 = new ListNode(5);
  ListNode* n6 = new ListNode(2);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  Solution solution;

  ListNode* node = solution.partition(n1, k);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}
