/*
 *  Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 *  
 *  k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 *  You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
 * 1. Create a dummy node pointing to head. Initialize `prevGroup` to dummy.
 *
 * 2. Loop until there are fewer than k nodes left:
 *    a. Use a `kth` pointer to move k steps forward from `prevGroup`.
 *       - If fewer than k nodes remain (kth is null), break.
 *
 * 3. Save `groupNext = kth->next` — the node after the k-group.
 *    - These pointers mark the boundaries of the k-group to reverse.
 *
 * 4. Reverse the k-group:
 *    a. Initialize `curr = prevGroup->next` (start of group), `prev = groupNext`.
 *    b. For k iterations:
 *       - Save next: `temp = curr->next`
 *       - Reverse link: `curr->next = prev`
 *       - Advance: `prev = curr`, `curr = temp`
 *
 * 5. Reconnect the reversed group:
 *    - `prevGroup->next = kth` (now the new head of group)
 *    - Advance `prevGroup` to the tail of the group (previously the head): `prevGroup = temp`
 *
 * 6. Return `dummy->next` — the new head of the modified list.
 */

class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prevGroup = dummy;

      while (true) {
        ListNode* kth = prevGroup;

        for (int i = 0; i < k && kth; i++) {
          kth = kth->next;
        }

        if (!kth) break;

        ListNode* groupNext = kth->next;
        ListNode* prev = groupNext;
        ListNode* curr = prevGroup->next;

        for (int i = 0; i < k; i++) {
          ListNode* temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
        }

        ListNode* temp = prevGroup->next;
        prevGroup->next = prev;
        prevGroup = temp;
 
      }
      return dummy->next;
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

  ListNode* node = solution.reverseKGroup(n1, k);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}
