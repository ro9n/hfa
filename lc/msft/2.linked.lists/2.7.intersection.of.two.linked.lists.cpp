#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *a = headA, *b = headB;
    if (!a || !b) return nullptr;
    
    int swp = 2;

    while (a != b) {
      a = a->next;
      b = b->next;

      if (!a) {
        if (swp) {
          a = headB;
          --swp;
        } else
          return nullptr;
      }
      if (!b) {
        if (swp) {
          b = headA, --swp;
        } else
          return nullptr;
      }
    }

    return a;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
