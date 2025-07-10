/*
 *  Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
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
 * Create a dummy node and point its next to the head of the list. Initialize a pointer 'prev' to the dummy node.
 *
 * Use a while loop to traverse the list while head is not null. 
 *   - If the current node's value equals the next node's value, 
 *     advance head until the values differ to skip all duplicates, 
 *     then set prev->next to head (bypassing the duplicate block).
 *   - Otherwise, move prev to head.
 *
 * In either case, advance head to the next node.
 *
 * Return dummy->next as the head of the modified list.
 */

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* dummy = new ListNode(0);
      dummy->next = head;
      ListNode* prev = dummy;

      while (head) {
        if (head->next && head->val == head->next->val) {
          int d = head->val;
          while (head && head->val == d) {
            head = head->next;
          }
          prev->next = head;
        }
        else {
          prev = head;
          head = head->next;
        }
      }

      return dummy->next;
    }
};

int main() {

  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(3);
  ListNode* n5 = new ListNode(4);
  ListNode* n6 = new ListNode(4);
  ListNode* n7 = new ListNode(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;

  Solution solution;

  ListNode* node = solution.deleteDuplicates(n1);

  while (node) {
    cout << node->val << ' ';
    node = node->next;
  }

  return 0;
}
