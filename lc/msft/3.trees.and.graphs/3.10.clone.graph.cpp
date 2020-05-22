#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* r) {
    if (!r) return r;

    map<Node*, Node*> m;  // visited -> new node

    queue<Node*> q;

    q.push(r);

    while (!q.empty()) {
      Node* u = q.front(); q.pop();

      if (!m.count(u)) m[u] = new Node(u->val);

      for (auto v : u->neighbors) {
        if (!m.count(v)) {
          m[v] = new Node(v->val);
          q.push(v);
        }
        m[u]->neighbors.emplace_back(m[v]);
      }
    }
    return m[r];
  }
};

#define eb emplace_back

int main() {
  Node *n1 = new Node(1), *n2 = new Node(2), *n3 = new Node(3),
       *n4 = new Node(4);

  n1->neighbors.eb(n2);
  n1->neighbors.eb(n4);

  n2->neighbors.eb(n1);
  n2->neighbors.eb(n3);

  n3->neighbors.eb(n2);
  n3->neighbors.eb(n4);

  n4->neighbors.eb(n1);
  n4->neighbors.eb(n3);

  auto s = new Solution();
  Node* g1 = s->cloneGraph(n1);

  return 0;
}