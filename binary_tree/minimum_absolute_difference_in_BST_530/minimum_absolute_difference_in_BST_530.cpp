/*
 *  Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
 */

#include <iostream>
#include <climits>

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
 * Minimum Absolute Difference in BST
 *
 * Approach:
 * 1. Perform an inorder traversal of the BST. This visits nodes in ascending order.
 * 2. Keep track of the previously visited node (prev).
 * 3. For each current node:
 *    - If prev is not null, compute the difference: curr->val - prev->val
 *    - Update minDiff = min(minDiff, difference)
 *    - Set prev = curr
 * 4. After traversal, return minDiff.
 *
 * Rationale:
 * - Inorder traversal of a BST produces a sorted sequence of values.
 * - The minimum absolute difference must occur between two adjacent values in this sequence.
 *
 * Complexity:
 * - Time: O(n) — each node is visited once.
 * - Space: O(h) — recursion stack, where h is the tree height.
 */

class Solution {
  private:
    TreeNode* prev = nullptr;
    int minDiff = INT_MAX;

    void inorder(TreeNode* root) {
      if (!root) return;
      inorder(root->left);

      if (prev) minDiff = min(minDiff, abs(root->val - prev->val));
      prev = root;

      inorder(root->right);
    }
  public:
    int getMinimumDifference(TreeNode* root) {
      inorder(root);
      return minDiff;
    }
};

int main() {
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n6 = new TreeNode(6);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n3 = new TreeNode(3);

  n4->left = n2;
  n4->right = n6;

  n2->left = n1;
  n2->right = n3;

  Solution solution;

  int minDiff = solution.getMinimumDifference(n4);

  cout << minDiff << endl;

  return 0;
}

