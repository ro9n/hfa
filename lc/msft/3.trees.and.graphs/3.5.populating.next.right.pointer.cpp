#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node *> q; q.push(root);

        while(!q.empty()) {
            int sib = q.size();
            Node *prev;

            while(sib--) {
                Node *front = q.front(); q.pop();
                if (prev) prev->next = front;

                prev = front;
                
                q.push(front->left);
                q.push(front->right);
            }
        }

        return root;
    }
};

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};