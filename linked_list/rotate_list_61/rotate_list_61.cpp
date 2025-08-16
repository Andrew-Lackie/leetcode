/*
 *  Given the head of a linked list, rotate the list to the right by k places.
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
 * 1. Edge case: if the list is empty or has one node, return head.
 *
 * 2. Compute the length `l` of the list and get the tail node.
 *    - While traversing, count nodes and move `tail` to the end.
 *
 * 3. Connect tail to head to form a cycle.
 *    - This allows us to rotate the list by simply shifting the break point.
 *
 * 4. Normalize k: set `k = k % l` to handle full-length rotations.
 *    - If k == 0, break the cycle and return head.
 *
 * 5. Find the new tail: move `l - k - 1` steps from head.
 *    - The node after this will be the new head.
 *
 * 6. Break the cycle:
 *    - Save `newHead = newTail->next`
 *    - Set `newTail->next = nullptr`
 *
 * 7. Return `newHead` as the new rotated list head.
 */

class Solution {
  public:
    ListNode* rotateRight(ListNode* head, int k) {
      if (!head || !head->next) return head;

      ListNode* tail = head;
      int l = 1;

      while (tail->next) {
        l++;
        tail = tail->next;
      }

      tail->next = head;

      k = k % l;

      if (k == 0) return head;

      ListNode* newTail = head;

      for (int i = 0; i < l - k - 1; i++) {
        newTail = newTail->next;
      }

      ListNode* newHead = newTail->next;
      newTail->next = nullptr;

      return newHead;
    }
};

int main() {

  int k = 2;

  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n5 = new ListNode(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Solution solution;

  ListNode* node = solution.rotateRight(n1, k);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}

