/*
 *  Given the root of a binary tree, return its maximum depth.
 *
 *  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
 * Create a recursive fuction maxDepth with an input of TreeNode*. If the node is nullptr then return 0. 
 * Otherwise, find the left and right depth an return 1 plus the maximum of the two depths.
 */

class Solution {
  public:
    int maxDepth(TreeNode* root) {
      if (!root) return 0;

      int left = maxDepth(root->left);
      int right = maxDepth(root->right);

      return 1 + max(left, right);
    }
};

int main() {
  TreeNode* n1 = new TreeNode(3);
  TreeNode* n2 = new TreeNode(9);
  TreeNode* n3 = new TreeNode(20);
  TreeNode* n4 = new TreeNode(15);
  TreeNode* n5 = new TreeNode(7);

  n1->left = n2;
  n1->right = n3;
  n3->left = n4;
  n3->right = n5;

  Solution solution;

  int depth = solution.maxDepth(n1);

  cout << depth << endl;

  return 0;
}
