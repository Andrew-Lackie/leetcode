/*
 *  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
 * To solve this problem, we need to check whether the left and right subtrees are mirror images of each other.
 * Create a helper function that takes two nodes as input: one from the left subtree and one from the right.
 *
 *  - If both input nodes are nullptr, return true — this means the current mirrored branches are empty and match.
 *  - If exactly one of the nodes is nullptr, return false — asymmetry exists.
 *  - If the values of the nodes differ, return false — mirror values must match.
 *  - Recursively compare:
 *      - The left child of the left node with the right child of the right node
 *      - The right child of the left node with the left child of the right node
 *    These pairs must both return true for the tree to be symmetric.
 *
 * In the main function, return true if the tree is empty, or call the helper on root->left and root->right.
 */

class Solution {
  private:
    bool isSymmetricRec(TreeNode* left, TreeNode* right) {
      if (!left && !right) return true;
      if (!left || !right) return false;
      if (left->val != right->val) return false;
      return isSymmetricRec(left->left, right->right) && isSymmetricRec(left->right, right->left);
    }

  public:
    bool isSymmetric(TreeNode* root) {
      if (!root) return true;
      return isSymmetricRec(root->left, root->right);
    }
};

int main() {
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(2);
  TreeNode* n4 = new TreeNode(3);
  TreeNode* n5 = new TreeNode(4);
  TreeNode* n6 = new TreeNode(4);
  TreeNode* n7 = new TreeNode(3);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = n7;

  Solution solution;

  bool isSymmetric = solution.isSymmetric(n1);

  cout << isSymmetric << endl;
}
