/*
 *  Given the root of a binary tree, invert the tree, and return its root.
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
 * To invert a binary tree, create a recursive function that performs a preorder traversal.
 * If the current node is nullptr, return nullptr — this is the base case.
 *
 * At each node:
 *   - Swap the left and right children.
 *   - Recursively call the function on the new left and right children.
 *
 * This ensures the entire subtree is inverted from the root downward.
 *
 * Finally, return the root node.
 */

class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
      if (!root) return nullptr;
      swap(root->left, root->right);
      invertTree(root->left);
      invertTree(root->right);
      return root;
    }

    void prettyPrint(TreeNode* node, int depth = 0) {
      if (!node) return;

      for (int i = 0; i < depth; ++i) cout << " ";

      cout << node->val << "\n";

      prettyPrint(node->left, depth + 1);
      prettyPrint(node->right, depth + 1);
    }
};

int main() {
  TreeNode* n1 = new TreeNode(4);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(7);
  TreeNode* n4 = new TreeNode(1);
  TreeNode* n5 = new TreeNode(3);
  TreeNode* n6 = new TreeNode(6);
  TreeNode* n7 = new TreeNode(9);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = n7;

  Solution solution;

  solution.prettyPrint(n1);

  TreeNode* node = solution.invertTree(n1);

  solution.prettyPrint(node);
}

