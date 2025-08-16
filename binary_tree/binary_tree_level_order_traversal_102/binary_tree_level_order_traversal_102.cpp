/*
 *  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
 */

#include <iostream>
#include <vector>
#include <queue>

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
 * To solve this problem, write a standard breadth order traversal. Initialize a queue and push the root node to it. While the queue isn't empty, loop through each node in the queue,
 * pushing the left and right nodes of the current node to the queue. Add the current node to a vector<int> object. Finally, push the vector<int> to a vector<vector<int>> object after each level.
 */

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<TreeNode*> q;
      vector<vector<int>> nodes;

      if (!root) return nodes;

      q.push(root);

      while (!q.empty()) {
        int n = q.size();
        vector<int> level;
        for (int i = 0; i < n; i++) {
          TreeNode* curr = q.front(); q.pop();
          if (curr->left) q.push(curr->left);
          if (curr->right) q.push(curr->right);
          level.push_back(curr->val);
        }
        nodes.push_back(level);
      }
      return nodes;
    }
};

int main() {
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n9 = new TreeNode(9);
  TreeNode* n20 = new TreeNode(20);
  TreeNode* n15 = new TreeNode(15);
  TreeNode* n7 = new TreeNode(7);

  n3->left = n9;
  n3->right = n20;

  n20->left = n15;
  n20->right = n7;

  Solution solution;

  vector<vector<int>> levels = solution.levelOrder(n3);

  for (const vector<int> level : levels) {
    for (const int c : level) cout << c << ' ';
  }

  return 0;
}
