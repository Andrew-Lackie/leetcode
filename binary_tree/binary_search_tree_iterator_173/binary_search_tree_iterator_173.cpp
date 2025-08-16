/*
 *  Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
 *
 *    - BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. 
 *      The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
 *
 *    - boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
 *
 *    - int next() Moves the pointer to the right, then returns the number at the pointer.
 *  
 *    - Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
 *  
 *  Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
 *
 *  You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.
 */

#include <iostream>
#include <stack>

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
 * For BSTIterator (in-order traversal of a BST):
 *
 * - In the constructor, push the leftmost path from the root onto a stack.
 *   This prepares the stack so that the next smallest node is always on top.
 *
 * - In next(), pop the top node from the stack — this is the current smallest.
 *   If the popped node has a right child, push its leftmost path onto the stack.
 *   Return the value of the popped node.
 *
 * - hasNext() returns true if the stack is non-empty, meaning more nodes are available.
 */

class BSTIterator {
  private:
    stack<TreeNode*> st;
    void pushTree(TreeNode* root) {
      while (root) {
        st.push(root);
        root = root->left;
      }
    }
  public:
    BSTIterator(TreeNode* root) {
      pushTree(root);
    }

    int next() {
      TreeNode* node = st.top();
      st.pop();
      if (node->right) pushTree(node->right);
      return node->val;
    }

    bool hasNext() {
      return !st.empty();
    }
};

int main() {

  TreeNode* n7 = new TreeNode(7);
  TreeNode* n3 = new TreeNode(3);
  TreeNode* n15 = new TreeNode(15);
  TreeNode* n9 = new TreeNode(9);
  TreeNode* n20 = new TreeNode(20);

  n7->left = n3;
  n7->right = n15;

  n15->left = n9;
  n15->right = n20;

  BSTIterator bSTIterator(n7);

  int a1 = bSTIterator.next();    // return 3
  cout << "return 3: ";
  cout << a1 << endl;                              

  int a2 = bSTIterator.next();    // return 7
  cout << "return 7: ";
  cout << a2 << endl;                              
                              
  bool b1 = bSTIterator.hasNext(); // return True
  cout << "return true: ";
  cout << b1 << endl;                              
 
  int a3 = bSTIterator.next();    // return 9

  cout << "return 9: ";
  cout << a3 << endl;                              
                                  
  bool b2 = bSTIterator.hasNext(); // return True
  cout << "return true: ";
  cout << b2 << endl;                              
 
  int a4 = bSTIterator.next();    // return 15
  cout << "return 15: ";
  cout << a4 << endl;                              
 
  bool b3 = bSTIterator.hasNext(); // return True
  cout << "return true: ";
  cout << b3 << endl;                              
 
  int a5 = bSTIterator.next();    // return 20
  cout << "return 20: ";
  cout << a5 << endl;                              
 
  bool b4 = bSTIterator.hasNext(); // return False
  cout << "return false: ";
  cout << b4 << endl;                              
 
};

