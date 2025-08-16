/*
 *  Given the roots of two binary trees p and q, write a function to check if they are the same or not.
 *  
 *  Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

/*
 * Create a recursive function "isSameTree" that takes in nodes from both trees.
 * If both 'p' and 'q' are NULL, the trees match at this branch; return true.
 * If exactly one of 'p' or 'q' is NULL, the trees differ structurally; return false.
 * If the values of 'p' and 'q' are different, the trees differ in content; return false.
 * Otherwise, recursively compare both the left and right subtrees.
 */

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (!p && !q) return true;
      if (!p || !q) return false;
      if (p->val != q->val) return false;
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
  TreeNode* p1 = new TreeNode(1);
  TreeNode* p2 = new TreeNode(2);
  TreeNode* p3 = new TreeNode(3);

  p1->left = p2;
  p1->right = p3;

  TreeNode* q1 = new TreeNode(1);
  TreeNode* q2 = new TreeNode(2);
  TreeNode* q3 = new TreeNode(3);

  q1->left = q2;
  q1->right = q3;

  Solution solution;

  bool isSameTree = solution.isSameTree(p1, q1);

  cout << isSameTree << endl;
}



