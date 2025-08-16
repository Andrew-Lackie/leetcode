/*
 * Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
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
 * To solve this, write a breadth first search algorithm: initialize a new variable "level" in the while loop control flow, add each number in the level to it, 
 * then divide by the size of the queue and append it to the vector.
 */

class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
      queue<TreeNode*> q;
      vector<double> nodes;

      if (!root) return nodes;

      q.push(root);

      while (!q.empty()) {
        int n = q.size();
        double level = 0.0;

        for (int i = 0; i < n; i++) {
          TreeNode* curr = q.front(); q.pop();
          if (curr->left) q.push(curr->left);
          if (curr->right) q.push(curr->right);
          level += curr->val;
        }

        nodes.push_back(level / n);
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

  vector<double> levels = solution.averageOfLevels(n3);

  for (const double level : levels) cout << level << ' ';

  return 0;
}
