/*
 *  A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
 *
 *  Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. 
 *  Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
 *  None of the pointers in the new list should point to nodes in the original list.
 *
 *  For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
 *
 *  Return the head of the copied linked list.
 *
 *  The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
 *    - val: an integer representing Node.val
 *    - random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
 *
 *  Your code will only be given the head of the original linked list.
 *
 *  */

class Node {
  public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
      val = _val;
      next = nullptr;
      random = nullptr;
    }
};

#include <iostream>
#include <unordered_map>

using namespace std;

/*
 * 
 * Create a hash map to store mappings from original nodes to their copied counterparts.
 *
 * First pass:
 *  - Traverse the original list.
 *  - For each node, create a new node with the same value.
 *  - Store the mapping from original → copy in the hash map.
 *
 * Second pass:
 *  - Traverse the original list again.
 *  - For each node:
 *      - Set copy->next = map[original->next]
 *      - Set copy->random = map[original->random]
 * 
 * Return the copied head: map[original_head]
 */

 Create a hash map to store mappings from original nodes to their copied counterparts.

class Solution {
  public:
    Node* copyRandomList(Node* head) {
      Node* dummy = new Node(0);
      Node* first = dummy;
      unordered_map<Node*, Node*> mp;

      Node* iterator = head;

      while (iterator) {
        first->next = new Node(iterator->val);
        mp[iterator] = first->next;
        iterator = iterator->next;
        first = first->next;
      }

      Node* second = dummy->next;

      while (head) {
        second->random = head->random == nullptr ? nullptr : mp[head->random];
        head = head->next;
        second = second->next;
      }

      return dummy->next;

    }
};

int main() {
  Node* n1 = new Node(7);
  Node* n2 = new Node(13);
  Node* n3 = new Node(11);
  Node* n4 = new Node(10);
  Node* n5 = new Node(1);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  n1->random = nullptr;
  n2->random = n1;
  n3->random = n5;
  n4->random = n3;
  n5->random = n1;

  Solution solution;

  Node* copy = solution.copyRandomList(n1);

  while (copy) {
    cout << "[ ";
    cout << copy->val;
    cout << ", ";
    if (copy->random) {
      cout << copy->random->val;
    }
    else {
      cout << "nullptr";
    }
    cout << " ]";
    
    if (copy->next) cout << ", ";

    copy = copy->next;
  }

  return 0;
}
