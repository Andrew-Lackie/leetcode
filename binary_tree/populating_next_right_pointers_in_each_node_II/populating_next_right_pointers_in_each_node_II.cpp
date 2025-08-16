/*
 *  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 *  Initially, all next pointers are set to NULL.
 */

#include <iostream>
#include <queue>

using namespace std;

class Node {
  public:
      int val;
      Node* left;
      Node* right;
      Node* next;

      Node() : val(0), left(NULL), right(NULL), next(NULL) {}

      Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

      Node(int _val, Node* _left, Node* _right, Node* _next)
          : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
  public:
    Node* connect(Node* root) {
      if (!root) return nullptr;
      queue<Node*> q;
      q.push(root);

      while (!q.empty()) {
        Node* prev = nullptr;
        int size = q.size();
        for (int i = 0; i < size; i++) {
          Node* node = q.front();
          q.pop();
          if (prev) prev->next = node;
          prev = node;
          if (node->left) q.push(node->left);
          if (node->right) q.push(node->right);
        }
        prev->next = nullptr;
      }
      return root;
    }

    void printNextPointers(Node* root) {
      Node* levelStart = root;

      while (levelStart) {
        Node* curr = levelStart;
        levelStart = nullptr;

        while (curr) {
          cout << curr->val << " ";

          // Set the start of the next level if not already set
          if (!levelStart) {
            if (curr->left) levelStart = curr->left;
            else if (curr->right) levelStart = curr->right;
          }

          curr = curr->next;
        }
        cout << "# ";
      }
    }
};

int main() {
  Node* n1 = new Node(1);
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Node* n5 = new Node(5);
  Node* n6 = new Node(7);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->right = n6;

  Solution solution;

  Node* node = solution.connect(n1);

  solution.printNextPointers(node);

  return 0;
}
