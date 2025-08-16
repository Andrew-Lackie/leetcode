/*
 *  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
 *  construct and return the binary tree.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

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
 * To solve this in O(n) time, create an unordered_map to store each value from the 'inorder' traversal
 * mapped to its index. This enables constant-time lookup of a value’s position in 'inorder'.
 *
 * Initialize a variable 'preStart' by reference to track the current root index in 'preorder' during recursion.
 *
 * Create a private helper function 'buildTreeRec' that takes the preorder vector, the reference to 'preStart',
 * the value-to-index map from 'inorder', and the current left/right bounds for the inorder slice.
 *
 * In the base case, if left > right, return nullptr — this means there are no more nodes in the current subtree.
 *
 * Otherwise:
 *   - Take the current root value from 'preorder[preStart]' and increment 'preStart' to advance to the next root.
 *   - Use the map to find the index of this root value in the 'inorder' traversal.
 *   - Construct a new TreeNode with the root value.
 *   - Recursively build the left subtree using the range [left, index - 1]
 *   - Recursively build the right subtree using the range [index + 1, right]
 *     This works because in an inorder traversal, everything left of the root index is the left subtree,
 *     and everything right of it is the right subtree.
 *
 * Return the root node after attaching its left and right subtrees.
 *
 * The top-level function 'buildTree' initializes the map and calls 'buildTreeRec' with left = 0 and right = inorder.size() - 1.
 */

class Solution {
  private:
    TreeNode* buildTreeRec(vector<int>& preorder, int& preStart, unordered_map<int,int>& mp, int left, int right) {
      if (left > right) return nullptr;
      int val = preorder[preStart++];

      int index = mp[val];

      TreeNode* root = new TreeNode(val);
      root->left = buildTreeRec(preorder, preStart, mp, left, index - 1);
      root->right = buildTreeRec(preorder, preStart, mp, index + 1, right);

      return root;
    }

  public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      unordered_map<int, int> mp;
      for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
      }

      int preStart = 0;

      return buildTreeRec(preorder, preStart, mp, 0, inorder.size() - 1);
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
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Solution solution;

  TreeNode* root = solution.buildTree(preorder, inorder);
  solution.prettyPrint(root);

  return 0;
}

