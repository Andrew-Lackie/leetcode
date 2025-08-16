/*
 *  Given the root of a complete binary tree, return the number of the nodes in the tree.
 *
 *  According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
 *
 *  It can have between 1 and 2h nodes inclusive at the last level h.
 *
 *  Design an algorithm that runs in less than O(n) time complexity.
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

/*
 * To count the total number of nodes in a binary tree:
 *
 *  - If the root is nullptr, return 0 — no node exists.
 *  - Recursively call the function on the left and right subtrees to count their nodes.
 *  - Return the sum of left count + right count + 1 (for the current root node).
 */

class Solution {
  public:
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {

  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n6 = new TreeNode(6);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;

  Solution solution;

  int count = solution.countNodes(n1);

  cout << count << endl;

  return 0;
}
