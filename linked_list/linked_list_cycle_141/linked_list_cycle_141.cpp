/*
 *  Given head, the head of a linked list, determine if the linked list has a cycle in it.
 *
 *  There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
 *
 *  Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
 *
 *  Return true if there is a cycle in the linked list. Otherwise, return false.
 */

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 *  If the head of the list is nullptr, then the list is empty and cannot contain a cycle; return false.
 *
 *  Initialize two pointers, `slow` and `fast`, both pointing to the head.
 *
 *  Iterate while both `fast` and `fast->next` are not null:
 *    - Move `slow` one step forward: `slow = slow->next`.
 *    - Move `fast` two steps forward: `fast = fast->next->next`.
 *    - If at any point `slow == fast`, a cycle exists; return true.
 *
 *  If the loop terminates, `fast` reached the end of the list; no cycle exists. Return false.
 */

class Solution {
  public:
    bool hasCycle(ListNode *head) {

      if (head == nullptr) return false;

      ListNode* slow = head;
      ListNode* fast = head;

      while (fast != nullptr && fast->next != nullptr ) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
      }

      return false;
    }
};

int main() {

  Solution solution;

  cout << "----- Example 1 -----" << endl;

  ListNode* n1 = new ListNode(3);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(0);
  ListNode* n4 = new ListNode(-4);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n2;

  bool hasCycle1 = solution.hasCycle(n1);

  cout << hasCycle1 << endl;

  cout << "----- Example 2 -----" << endl;

  ListNode* n5 = new ListNode(1);
  ListNode* n6 = new ListNode(2);

  n5->next = n6;
  n6->next = n5;

  bool hasCycle2 = solution.hasCycle(n5);

  cout << hasCycle2 << endl;

  cout << "----- Example 3 -----" << endl;

  ListNode* n7 = new ListNode(1);

  bool hasCycle3 = solution.hasCycle(n7);

  cout << hasCycle3 << endl;

  return 0;
}
