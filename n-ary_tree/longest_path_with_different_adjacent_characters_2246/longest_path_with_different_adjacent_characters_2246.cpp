/*
 * You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. 
 * The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.
 *
 * You are also given a string s of length n, where s[i] is the character assigned to node i.
 *
 * Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 2246. Longest Path With Different Adjacent Characters
 *
 * Approach:
 * 1) Build children adjacency from parent[]:
 *    - root = -1 initially.
 *    - For i in [0..n): if parent[i] == -1 → root = i; else children[parent[i]].push_back(i).
 *
 * 2) Postorder DFS returning the best downward chain length (in NODES) starting at u
 *    subject to s[child] != s[u].
 *    - Maintain two best child contributions t1 >= t2.
 *    - For each child v:
 *        d = dfs(v)
 *        if (s[v] == s[u]) continue;          // cannot extend through same char
 *        if (d > t1) { t2 = t1; t1 = d; }
 *        else if (d > t2) { t2 = d; }
 *    - Update global answer: best = max(best, 1 + t1 + t2)   // child→u→child
 *    - Return 1 + t1 (best downward chain via u).
 *
 * Notes:
 * - Initialize best = 1 (single node).
 * - Result is already in NODES (no conversion to edges).
 * - This is O(n) time, O(n) space (children + recursion stack).
 * - If the tree can be very deep (chain), use an iterative postorder to avoid stack overflow.
 */

class Solution {
  private:
    int n;
    vector<vector<int>> children;
    int best = 1;

    int dfs(int u, string& s) {
      int t1 = 0, t2 = 0;
      for (int& v : children[u]) {
        int d = dfs(v, s);
        if (s[u] == s[v]) continue;
        if (d > t1) { t2 = t1; t1 = d; }
        else t2 = max(t2, d);
      }
      best = max(best, 1 + t1 + t2);
      return 1 + t1;
    }

  public:
    explicit Solution(int n) : n(n), children(n) {}
    int longestPath(vector<int>& parent, string s) {
      int root = -1;

      for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) root = i;
        else children[parent[i]].push_back(i);
      }

      dfs(root, s);

      return best;
    }
};

int main() {
  vector<int> parent = {-1, 0, 0, 0};
  string s = "aabc";

  Solution solution(parent.size());

  int longestPath = solution.longestPath(parent, s);
  
  cout << longestPath << endl;

  return 0;
}
