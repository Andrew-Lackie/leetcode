/*
 *  Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 *  Implement the LRUCache class:
 *
 *    - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 *
 *    - int get(int key) Return the value of the key if the key exists, otherwise return -1.
 *
 *    - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
 *      If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 *
 *  The functions get and put must each run in O(1) average time complexity.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
  int key, value;
  Node* prev;
  Node* next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DLL {
  private:
    Node* head;
    Node* tail;

  public:
    DLL() {
      head = new Node(0, 0);
      tail = new Node(0, 0);
      head->next = tail;
      tail->prev = head;
    }

    void insertHead(Node* node) {
      node->next = head->next;
      node->prev = head;
      head->next->prev = node;
      head->next = node;
    }

    Node* remove(Node* node) {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      return node;
    }

    Node* removeTail() {
      return remove(tail->prev);
    }
};

/*
 * Doubly Linked List (DLL):
 *  - Define a Node struct that stores (key, value) and pointers to prev and next nodes.
 *  - Implement a DLL class with:
 *      - insertHead(Node*): adds a node directly after the dummy head.
 *      - remove(Node*): unlinks a given node from the list.
 *      - removeTail(): removes the node just before the dummy tail (least recently used).
 *  - Use dummy head and tail nodes to avoid null checks and simplify edge case handling.
 *
 * LRUCache:
 *  - Maintain three members:
 *      - _capacity: the max number of items allowed in the cache.
 *      - cache: an unordered_map from key → Node* for O(1) lookup.
 *      - list: the DLL instance to track usage order (MRU at head, LRU at tail).
 *
 *  - get(key):
 *      - If key is not in cache, return -1.
 *      - Otherwise, promote the node to the front (MRU) and return its value.
 *
 *  - put(key, value):
 *      - If key exists: update its value and move it to the front.
 *      - If key does not exist:
 *          - Create a new node and insert it at the front.
 *          - Add the node to the cache map.
 *          - If cache size exceeds capacity:
 *              - Remove the tail node from the list.
 *              - Erase it from the map and deallocate memory.
 */

class LRUCache {
  private:
    int _capacity;
    unordered_map<int, Node*> cache;
    DLL list;
  public:
    LRUCache(int capacity) {
      _capacity = capacity;
    }

    int get(int key) {
      if (!cache.count(key)) return -1;
      Node* node = cache[key];
      list.remove(node);
      list.insertHead(node);
      return node->value;
    }

    void put(int key, int value) {
      if (cache.count(key)) {
        Node* node = cache[key];
        node->value = value;
        list.remove(node);
        list.insertHead(node);
      }
      else {
        Node* node = new Node(key, value);
        list.insertHead(node);
        cache[key] = node;
        if (cache.size() > _capacity) {
          Node* node = list.removeTail();
          cache.erase(node->key);
          delete node;
        }
      }
    }
};

int main() {
  LRUCache lRUCache(2);
  lRUCache.put(1, 1); // cache is {1=1}
  lRUCache.put(2, 2); // cache is {1=1, 2=2}
  int n1 = lRUCache.get(1);    // return 1
  cout << n1 << endl;
  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  int n2 = lRUCache.get(2);    // returns -1 (not found)
  cout << n2 << endl;
  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  int n3 = lRUCache.get(1);    // return -1 (not found)
  cout << n3 << endl;
  int n4 = lRUCache.get(3);    // return 3
  cout << n4 << endl;
  int n5 = lRUCache.get(4);    // return 4
  cout << n5 << endl;
}
