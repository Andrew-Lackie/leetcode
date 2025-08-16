/*
 *  Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 *
 *  A leaf is a node with no children.
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
 * This problem asks whether there exists a root-to-leaf path such that the sum of node values equals targetSum.
 * Use a preorder-style DFS traversal to explore all paths:
 *
 *  - If the root is nullptr, return false — no path can exist from an empty node.
 *  - Subtract the current node's value from targetSum to compute the remaining required sum.
 *  - If the current node is a leaf (both left and right are nullptr) and the remaining sum is zero, return true — a valid path has been found.
 *  - Otherwise, recursively check the left and right subtrees with the updated target sum.
 *    Return true if either recursive call returns true.
 */

class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum) {
      if (!root) return false;
      int diff = targetSum - root->val;
      if (!root->left && !root->right && diff == 0) return true;
      return hasPathSum(root->left, diff) || hasPathSum(root->right, diff);
    }
};

int main() {
  int targetSum = 22;

  TreeNode* n1 = new TreeNode(5);
  TreeNode* n2 = new TreeNode(4);
  TreeNode* n3 = new TreeNode(11);
  TreeNode* n4 = new TreeNode(7);
  TreeNode* n5 = new TreeNode(2);
  TreeNode* n6 = new TreeNode(8);
  TreeNode* n7 = new TreeNode(13);
  TreeNode* n8 = new TreeNode(4);
  TreeNode* n9 = new TreeNode(1);

  n1->left = n2;
  n1->right = n6;

  n2->left = n3;

  n3->left = n4;
  n3->right = n5;

  n6->left = n7;
  n6->right = n8;

  n8->right = n9;

  Solution solution;

  bool hasPathSum = solution.hasPathSum(n1, targetSum);

  cout << hasPathSum << endl;
}
