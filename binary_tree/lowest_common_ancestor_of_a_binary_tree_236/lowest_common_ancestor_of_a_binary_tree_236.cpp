/*
 *  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *  According to the definition of LCA on Wikipedia: 
 *  “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 */

#include <iostream>

using namespace std;

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val;
  TreeNode() : val(0), left(NULL), right(NULL) {}
  TreeNode(int val) : val(val), left(NULL), right(NULL) {}
  TreeNode(int val, TreeNode* left, TreeNode* right) : val(0), left(left), right(left) {}
};

/*
 * To find the Lowest Common Ancestor (LCA) in a binary tree:
 *
 *  - If the current root is nullptr, return nullptr.
 *  - If the current root is equal to either p or q, return root — this is a match.
 *  - Recursively search the left and right subtrees.
 *  - If both recursive calls return non-null, then p and q are found in different subtrees — return root as the LCA.
 *  - If only one side returns non-null, return that side — it means both p and q are located in the same subtree.
 */

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return nullptr;
      if (root == p || root == q) return root;
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      if (left && right) return root;
      return left ? left : right;
    }
};

int main() {

  TreeNode* n1 = new TreeNode(3);
  TreeNode* n2 = new TreeNode(5);
  TreeNode* n3 = new TreeNode(1);

  n1->left = n2;
  n1->right = n3;

  TreeNode* n4 = new TreeNode(6);
  TreeNode* n5 = new TreeNode(2);

  n2->left = n4;
  n2->right = n5;

  TreeNode* n6 = new TreeNode(7);
  TreeNode* n7 = new TreeNode(4);

  n5->left = n6;
  n5->right = n7;

  TreeNode* n8 = new TreeNode(0);
  TreeNode* n9 = new TreeNode(8);

  n3->left = n8;
  n3->right = n9;

  Solution solution;

  TreeNode* lca = solution.lowestCommonAncestor(n1, n2, n3);

  cout << lca->val << endl;

  return 0;
}

