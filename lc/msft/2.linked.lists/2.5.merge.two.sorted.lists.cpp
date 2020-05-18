#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1)
      return l2;
    else if (!l2)
      return l1;

    ListNode *r = new ListNode(0), *h = r;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        h->next = new ListNode(l1->val);
        l1 = l1->next;
        if (!l1) {
          h->next->next = l2;
          break;
        }
      } else {
        h->next = new ListNode(l2->val);
        l2 = l2->next;
        if (!l2) {
          h->next->next = l1;
          break;
        }
      }

      h = h->next;
    }

    return r->next;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
