/*
 * Given the root of a binary tree, return the length of the diameter of the tree.
 *
 * The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
 * The length of a path between two nodes is represented by the number of edges between them.
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
 * 543. Diameter of Binary Tree
 *
 * Recurrence (postorder):
 * - Let height(node) be in NODES.
 * - Base: if (!node) return 0.
 * - Recurse: lh = height(node->left), rh = height(node->right).
 * - Local diameter in NODES: 1 + lh + rh  (path through node).
 * - Update global: best = max(best, 1 + lh + rh).
 * - Return height in NODES: 1 + max(lh, rh).
 *
 * Answer:
 * - If root is null, return 0.
 * - Otherwise return best - 1 to convert NODES → EDGES (problem expects edges).
 *
 * Complexity:
 * - Time: O(n)  (each node visited once)
 * - Space: O(h) (recursion stack)
 */

class Solution {
  private:
    int best = 0;
    int diameterOfBinaryTreeRec(TreeNode* node) {
      if (!node) return 0;
      int lh = diameterOfBinaryTreeRec(node->left);
      int rh = diameterOfBinaryTreeRec(node->right);

      int localDiameter = 1 + lh + rh;

      best = max(best, localDiameter);

      return 1 + max(lh, rh);
    }
  public:
    int diameterOfBinaryTree(TreeNode* root) {
      if (!root) return 0;
      diameterOfBinaryTreeRec(root);
      return best - 1;
    }
};

int main() {

  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  Solution solution;

  int diameter = solution.diameterOfBinaryTree(n1);

  cout << diameter << endl;

  return 0;
}
