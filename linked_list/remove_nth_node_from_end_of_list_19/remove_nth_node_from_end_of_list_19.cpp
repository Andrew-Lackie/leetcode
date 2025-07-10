/*
 *  Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
 * Initialize a length variable 'l' and iterate through the list to compute the total length.
 *
 * If n equals the length of the list, return head->next (i.e., remove the first node).
 *
 * Otherwise, iterate again to the (l - n - 1)th node (the node before the one to remove).
 *
 * Set that node's next pointer to skip the nth node from the end by assigning: curr->next = curr->next->next.
 *
 * Return the (possibly unchanged) head of the list.
 */

class Solution {
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* curr = head;
      int l = 0;

      while (curr) {
        l++;
        curr = curr->next;
      }

      curr = head;

      for (int i = 0; i < l - n - 1; i++) {
        curr = curr->next;
      }

      if (l == n) return head->next;

      curr->next = curr->next->next;

      return head;
    }
};

int main() {

  int n = 2;

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

  ListNode* node = solution.removeNthFromEnd(n1, 2);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}

