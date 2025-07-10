/*
 *  Given the head of a singly linked list and two integers left and right where left <= right, 
 *  reverse the nodes of the list from position left to position right, and return the reversed list.
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
 * Create a dummy node and set its next pointer to the head of the list.
 *
 * Initialize a pointer "prev" to dummy and advance it to the node just before the "left" position.
 *
 * Initialize a pointer "curr" to prev->next (the first node in the sublist to be reversed).
 *
 * Iterate (right - left) times:
 *  - Let "temp" be curr->next (the node to be repositioned).
 *  - Remove "temp" from the list by setting curr->next = temp->next.
 *  - Insert "temp" immediately after "prev" by:
 *      - Setting temp->next = prev->next.
 *      - Setting prev->next = temp.
 *
 * Return dummy->next as the new head of the modified list.
 */

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;

      ListNode* prev = dummy;

      for (int i = 1; i < left; i++) {
        prev = prev->next;
      }

      ListNode* curr = prev->next;
      for (int i = 0; i < right - left; i++) {
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
      }

      return dummy->next;
    }
};

int main() {

  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(4);
  ListNode* n5 = new ListNode(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  int left = 2;
  int right = 4;

  Solution solution;

  ListNode* node = solution.reverseBetween(n1, left, right);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}
