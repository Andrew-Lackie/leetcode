/*
 *  Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
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
 * Kth Smallest Element in a BST
 *
 * Approach:
 * 1. Perform an inorder traversal of the BST — nodes are visited in ascending order.
 * 2. If the current node is null or 'found' is true, return immediately (early termination).
 * 3. Traverse the left subtree.
 * 4. Increment 'count' and check if it equals k:
 *    - If yes, record the current node's value as 'kth' and set 'found' = true.
 * 5. Traverse the right subtree.
 * 6. After traversal, return 'kth'.
 *
 * Rationale:
 * - Inorder traversal of a BST yields values in sorted order.
 * - The kth smallest element will be the kth node visited in this sequence.
 *
 * Complexity:
 * - Time: O(h + k) — Stops early once the kth element is found (worst case O(n) if k = n).
 * - Space: O(h) — Recursion stack, where h is the tree height.
 */

class Solution {
  private:
    int kth = INT_MAX;
    int count = 0;
    bool found = false;

    void inorder(TreeNode* node, int& k) {
      if (!node || found) return;

      inorder(node->left, k);

      if (++count == k) {
        kth = node->val;
        found = true;
        return;
      }

      inorder(node->right, k);
    }
  public:
    int kthSmallest(TreeNode* root, int k) {
      inorder(root, k);
      return kth;
    }
};

int main() {

  TreeNode* n3 = new TreeNode(3);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n4 = new TreeNode(4);

  n3->left = n1;
  n3->right = n4;

  n1->right = n2;

  int k = 1;

  Solution solution;

  int kthSmallest = solution.kthSmallest(n3, k);

  cout << kthSmallest << endl;

  return 0;
}
