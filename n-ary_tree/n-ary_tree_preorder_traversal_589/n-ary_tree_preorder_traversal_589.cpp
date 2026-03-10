/*
 * Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
 *
 * Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
  int val;
  vector<Node*> children;
  Node() {}
  Node(int val) : val(val) {}
  Node(int val, vector<Node*> children) : val(val), children(children) {}
};

/*
 * To solve this, write a standard preorder traversal.
 */

class Solution {
  private:
    vector<int> nodes;

    void dfs(Node* node) {
      if (!node) return;
      nodes.push_back(node->val);
      for (auto& child : node->children) {
        dfs(child);
      }
    }
  public:
    vector<int> preorder(Node* root) {
      dfs(root);
      return nodes;
    }

    vector<int> preorder_iterative(Node* root) {
      stack<Node*> st;
      vector<int> nodes;

      if (!root) return nodes;

      st.push(root);

      while (!st.empty()) {
        Node* curr = st.top(); st.pop();
        nodes.push_back(curr->val);
        for (int i = curr->children.size() - 1; i >= 0; i--) st.push(curr->children[i]);
      }
      return nodes;
    }
};

int main() {

  // Create leaf nodes
  Node* n5 = new Node(5);
  Node* n6 = new Node(6);

  // Node 3 has children [5, 6]
  Node* n3 = new Node(3, {n5, n6});

  // Node 2 and 4 have no children
  Node* n2 = new Node(2);
  Node* n4 = new Node(4);

  // Root 1 has children [3, 2, 4]
  Node* root = new Node(1, {n3, n2, n4});

  Solution solution;

  vector<int> nodes = solution.preorder(root);

  cout << "Recursion: ";
  for (int& node : nodes) cout << node << ' ';
  cout << endl;

  vector<int> nodes_iterative = solution.preorder_iterative(root);

  cout << "Iterative: ";
  for (int& node : nodes_iterative) cout << node << ' ';
  cout << endl;

  return 0;
}
