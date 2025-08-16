/*
 *  You are given the root of a binary tree containing digits from 0 to 9 only.
 *    - Each root-to-leaf path in the tree represents a number.
 *  
 *  Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
 *
 *  A leaf node is a node with no children.
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
 * Initialize a recursive helper function that returns an integer. It takes a TreeNode* "root" and an int "curr":
 *  - If root is nullptr, return 0 — this represents an empty path.
 *  - Compute a new integer "next" as curr * 10 + root->val. This accumulates the number formed from root to the current node.
 *  - If both root->left and root->right are nullptr, this is a leaf node — return "next".
 *  - Otherwise, recursively call the function on both the left and right subtrees and return their sum.
 */

class Solution {
  public:
    int sumNumbers(TreeNode* root) {
      return sumNumbersRec(root, 0);
    }
  private:
    int sumNumbersRec(TreeNode* root, int curr) {
      if (!root) return 0;
      int next = curr * 10 + root->val;
      if (!root->left && !root->right) return next;
      return sumNumbersRec(root->left, next) + sumNumbersRec(root->right, next);
    }
};

int main() {
  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);

  n1->left = n2;
  n1->right = n3;

  Solution solution;

  int sum = solution.sumNumbers(n1);

  cout << sum << endl;

  return 0;
}
