/*
 *  Given the root of a binary tree, flatten the tree into a "linked list":
 *    - The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
 *    - The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 */

#include <iostream>

using namespace std;

struct TreeNode {
  public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

/*
 * Solve this problem using a reverse preorder traversal: right → left → root.
 *
 *  - Initialize a private class variable "prev" to track the previously processed node.
 *  - If the current root is nullptr, return — this is the base case.
 *  - Recursively call flatten on the right subtree first, then the left subtree.
 *    This ensures that when you backtrack, you are building the flattened list from the end toward the start.
 *  - After processing both children:
 *      - Set root->right to prev (the previously visited node).
 *      - Set root->left to nullptr (since we are flattening into a right-skewed list).
 *      - Update prev to point to the current root.
 */

class Solution {
  private:
    TreeNode* prev = nullptr;
  public:
    void flatten(TreeNode* root) {
      if (!root) return;
      flatten(root->right);
      flatten(root->left);
      root->right = prev;
      root->left = nullptr;
      prev = root;
    }
};

int main() {
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);
  TreeNode* n6 = new TreeNode(6);

  n1->left = n2;
  n1->right = n5;

  n2->left = n3;
  n2->right = n4;

  n5->right = n6;

  Solution solution;

  solution.flatten(n1);

  while (n1) {
    cout << n1->val << endl;
    n1 = n1->right;
  }

  return 0;
}
