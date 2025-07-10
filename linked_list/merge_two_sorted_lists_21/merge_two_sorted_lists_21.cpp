/*
 *  You are given the heads of two sorted linked lists list1 and list2.
 *
 *  Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
 *
 *  Return the head of the merged linked list.
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
 *  Initialize a dummy node with value 0, and set a pointer `curr` to it.
 *
 *  While both `list1` and `list2` are not null:
 *    - If `list1->val` is less than or equal to `list2->val`, set `curr->next` to `list1` and advance `list1`.
 *    - Otherwise, set `curr->next` to `list2` and advance `list2`.
 *    - Move `curr` to `curr->next`.
 *
 *  After the loop, one list may still have remaining nodes.
 *  Set `curr->next` to the non-null list (either `list1` or `list2`).
 *
 *  Return `dummy->next` — the head of the merged sorted list.
 */

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;

      while (list1 && list2) {
        if (list1->val <= list2->val) {
          curr->next = list1;
          list1 = list1->next;
        }
        else {
          curr->next = list2;
          list2 = list2->next;
        }
        curr = curr->next;
      }

      curr->next = list1 ? list1 : list2;

      return dummy->next;
    }
};

int main() {
  ListNode* a1 = new ListNode(1);
  ListNode* a2 = new ListNode(2);
  ListNode* a3 = new ListNode(4);

  a1->next = a2;
  a2->next = a3;
 
  ListNode* b1 = new ListNode(1);
  ListNode* b2 = new ListNode(3);
  ListNode* b3 = new ListNode(4);

  b1->next = b2;
  b2->next = b3;
  
  Solution solution;

  ListNode* merged = solution.mergeTwoLists(a1, b1);

  while (merged) {
    cout << merged->val << ' ';
    merged = merged->next;
  }
  cout << endl;
}
