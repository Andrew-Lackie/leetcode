/*
 *  Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, 
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
 * mapped to its index. This allows constant-time lookup of a value’s position in 'inorder'.
 *
 * Initialize an integer variable 'rootpos' by reference and set it to the last index in 'postorder'.
 * This tracks the current root position during recursion, moving from right to left.
 *
 * Create a helper function 'buildTreeRec' that takes:
 *   - the 'postorder' vector,
 *   - the reference to 'rootpos',
 *   - the value-to-index map from 'inorder',
 *   - and the current left/right bounds for the inorder slice.
 *
 * Base case: if 'left > right', return nullptr — this indicates an empty subtree.
 *
 * Recursive step:
 *   - Take the current root value from postorder[rootpos] and decrement 'rootpos'.
 *   - Use the map to find this value’s index in the inorder array.
 *   - Create a new TreeNode with that value.
 *   - Recursively build the right subtree first using the range [index + 1, right]
 *   - Then recursively build the left subtree using the range [left, index - 1]
 *     This order is required because we're processing postorder in reverse (root → right → left).
 *
 * After building both subtrees, return the root node.
 *
 * The top-level function 'buildTree' initializes the map and rootpos, and then calls 'buildTreeRec'
 * with the full inorder range: left = 0, right = inorder.size() - 1.
 */

class Solution {
  private:
    TreeNode* buildTreeRec(vector<int>& postorder, unordered_map<int,int>& mp, int& rootpos, int left, int right) {
      if (left > right) return nullptr;
      if (rootpos < 0) return nullptr;

      int rootval = postorder[rootpos--];
      int index = mp[rootval];

      TreeNode* root = new TreeNode(rootval);
      
      root->right = buildTreeRec(postorder, mp, rootpos, index + 1, right);
      root->left = buildTreeRec(postorder, mp, rootpos, left, index - 1);

      return root;
    }

  public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      unordered_map<int,int> mp;

      for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
      }

      int rootpos = postorder.size() - 1;

      return buildTreeRec(postorder, mp, rootpos, 0, inorder.size() - 1);
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
  vector<int> postorder = {9, 15, 7, 20, 3};
  vector<int> inorder = {9, 3, 15, 20, 7};

  Solution solution;

  TreeNode* node = solution.buildTree(inorder, postorder);

  solution.prettyPrint(node);
}
