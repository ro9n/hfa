#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    map<Node*, Node*> m;
    Node *h = head;

    while(h) {
      m[h] = new Node(h->val);
      h = h->next;
    }

    h = head;
    while(h) {
      m[h]->next = h->next ? m[h->next] : nullptr;
      m[h]->random = h->random ? m[h->random] : nullptr;
      h = h->next;
    }

    return head ? m[head] : nullptr;
  }
};

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int v) {
    val = v;
    next = 0;
    random = 0;
  }
};
