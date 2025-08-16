/*
 *  A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. 
 *  A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
 *  
 *  The path sum of a path is the sum of the node's values in the path.
 *
 *  Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
 * Use post-order traversal to explore all possible paths in the tree.
 *
 * In the recursive helper function (maxPathSumRec):
 *  - If the root is nullptr, return 0.
 *  - Compute the left and right gains as the maximum of 0 and the recursive calls on the left and right children.
 *    (We use 0 to discard any negative path sums.)
 *
 *  - The local maximum path sum is the sum of left gain + root value + right gain.
 *    If this local sum is greater than the global maximum, update the global max.
 *
 *  - Return the root value plus the maximum of left or right gain — this represents the max one-sided path 
 *    that can be extended upward to the parent.
 *
 * In the main function (maxPathSum), call the helper on the root and return the global maximum path sum.
 */

class Solution {
  private:
    int globalMax;

    int maxPathSumRec(TreeNode* root) {
      if (!root) return 0;

      int leftGain = max(0, maxPathSumRec(root->left));
      int rightGain = max(0, maxPathSumRec(root->right));

      int localMax = leftGain + rightGain + root->val;

      globalMax = max(globalMax, localMax);

      return root->val + max(leftGain, rightGain);
    }

  public:
    Solution() : globalMax(INT_MIN) {}

    int maxPathSum(TreeNode* root) {
      maxPathSumRec(root);
      return globalMax;
    }
};

int main() {
  TreeNode* n1 = new TreeNode(-10);
  TreeNode* n2 = new TreeNode(9);
  TreeNode* n3 = new TreeNode(20);
  TreeNode* n4 = new TreeNode(15);
  TreeNode* n5 = new TreeNode(7);

  n1->left = n2;
  n1->right = n3;

  n3->left = n4;
  n3->right = n5;

  Solution solution;

  int maxVal = solution.maxPathSum(n1);

  cout << maxVal << endl;

  return 0;
}
