/*
 * Given the root of an n-ary tree, return the postorder traversal of its nodes' values.
 * Nary-Tree input serialization is represented in their level order traversal.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
 * To solve this, write a standard postorder traversal.
 */


class Solution {
  private:
    vector<int> nodes;
    void dfs(Node* node) {
      if (!node) return;
      for (auto& child : node->children) dfs(child);
      nodes.push_back(node->val);
    }
  public:
    vector<int> postorder(Node* root) {
      dfs(root);
      return nodes;
    }

    vector<int> postorder_iterative(Node* root) {
      vector<int> nodes;
      stack<pair<Node*, bool>> st;
      if (!root) return nodes;

      st.push({ root, false});

      while (!st.empty()) {
        auto [u, seen] = st.top(); st.pop();
        if (!u) continue;
        if (seen) nodes.push_back(u->val);
        else {
          st.push({ u, true });
          for (int i = u->children.size() - 1; i >= 0; i--) st.push({u->children[i], false});
        }
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

  vector<int> nodes = solution.postorder(root);

  cout << "Recursion: ";
  for (int& node : nodes) cout << node << ' ';
  cout << endl;

  vector<int> nodes_iterative = solution.postorder_iterative(root);

  cout << "Iterative: ";
  for (int& node : nodes_iterative) cout << node << ' ';
  cout << endl;

  return 0;
}
