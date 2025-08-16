/*
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 */

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

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
 * Zigzag Level-Order Traversal (Binary Tree)
 *
 * Approach:
 * 1. If the root is null, return an empty vector.
 * 2. Initialize:
 *    - queue<TreeNode*> q containing the root node
 *    - bool leftToRight = true to track the traversal direction
 * 3. While the queue is not empty:
 *    a. Get the number of nodes at the current level (n = q.size()).
 *    b. Create a deque<int> level to hold node values for this level.
 *    c. For each node in this level:
 *       - Pop the node from the queue
 *       - If leftToRight is true → push_back(node->val) into level
 *       - Else → push_front(node->val) into level
 *       - Always enqueue node->left then node->right (if they exist)
 *    d. Convert the deque to a vector<int> and append to result.
 *    e. Flip the leftToRight boolean for the next level.
 * 4. Return the vector<vector<int>> containing all levels in zigzag order.
 *
 * Complexity:
 * - Time: O(n) — each node is visited exactly once.
 * - Space: O(n) — for the queue and one level's worth of storage.
 */

class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> nodes;
      queue<TreeNode*> q;
      bool leftToRight = true;

      if (!root) return nodes;

      q.push(root);

      while (!q.empty()) {
        int n = q.size();
        deque<int> level;
        for (int i = 0; i < n; i++) {
          TreeNode* curr = q.front(); q.pop();
          if (curr->left) q.push(curr->left);
          if (curr->right) q.push(curr->right);
          if (leftToRight) level.push_back(curr->val);
          else level.push_front(curr->val);
        }
        leftToRight = !leftToRight;
        nodes.emplace_back(level.begin(), level.end());
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

  vector<vector<int>> levels = solution.zigzagLevelOrder(n3);

  for (const vector<int> level : levels) {
    for (const int c : level) cout << c << ' ';
  }

  return 0;
}
