/*
 *  Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 */

#include <iostream>
#include <queue>
#include <vector>

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
 * To solve this, write a breadth first search algorithm, keeping only the last node in the queue (when i == n - 1).
 */

class Solution {
  public:
    vector<int> rightSideView(TreeNode* root) {
      vector<int> nodes;
      queue<TreeNode*> q;

      if (!root) return nodes;

      q.push(root);

      while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
          TreeNode* curr = q.front(); q.pop();
          if (curr->left) q.push(curr->left);
          if (curr->right) q.push(curr->right);
          if (i == n - 1) nodes.push_back(curr->val);
        }
      }

      return nodes;
    }
};

int main() {

  TreeNode* n1 = new TreeNode(1);
  TreeNode* n2 = new TreeNode(2);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n4 = new TreeNode(4);
  TreeNode* n5 = new TreeNode(5);

  n1->left = n2;
  n1->right = n3;
  
  n2->right = n5;

  n2->right = n5;

  n3->right = n4;

  Solution solution;

  vector<int> nodes = solution.rightSideView(n1);

  for (const int a : nodes) cout << a << ' ';

  return 0;
}
