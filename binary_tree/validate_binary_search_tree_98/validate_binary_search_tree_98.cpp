/*
 *  Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 *
 *  A valid BST is defined as follows:
 *    - The left subtree of a node contains only nodes with keys strictly less than the node's key.
 *    - The right subtree of a node contains only nodes with keys strictly greater than the node's key.
 *    - Both the left and right subtrees must also be binary search trees.
 */

#include <iostream>
#include <stack>
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
 * 98. Validate Binary Search Tree
 *
 * Approach:
 * 1) Do an iterative inorder traversal using an explicit stack (inorder yields ascending values in a BST).
 * 2) Track the previously visited value:
 *      - Option A: use a sentinel (long long prev = LLONG_MIN).
 *      - Option B: use a bool first = true and skip the first compare.
 * 3) At each popped node:
 *      - If not first and (curr->val <= prev), return false.
 *      - Update prev = curr->val.
 * 4) If traversal finishes, return true.
 *
 * Rationale:
 * - Inorder over a BST must be strictly increasing; any non-increase violates BST ordering.
 *
 * Complexity:
 * - Time: O(n) — worst case scenario is O(n) where n is the node count.
 * - Space: O(h) — explicit stack holds up to the tree height h.
 */

class Solution {
  public:
    bool isValidBST(TreeNode* root) {
      stack<TreeNode*> st;
      TreeNode* curr = root;
      long long prevVal = LLONG_MIN;

      while (curr || !st.empty()) {
        while (curr) {
          st.push(curr);
          curr = curr->left;
        }

        curr = st.top(); st.pop();

        if (curr->val <= prevVal) return false;

        prevVal = curr->val;

        curr = curr->right;
      }

      return true;
    }
};

int main() {
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n3 = new TreeNode(3);

  n2->left = n1;
  n2->right = n3;

  Solution solution;

  bool isValidBST = solution.isValidBST(n2);

  cout << isValidBST << endl;

  return 0;
}
