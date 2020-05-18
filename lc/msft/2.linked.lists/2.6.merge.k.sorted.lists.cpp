#include <bits/stdc++.h>

using namespace std;

class Solution {
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

 public:
  ListNode* mergeKLists(vector<ListNode*>& L) {
    int n = L.size();

    while (n > 1) {
      int j = 0;
      for (int i = 0; i + 1 < n; i += 2) {
        L[j++] = mergeTwoLists(L[i], L[i + 1]);
      }
      if (n & 1) L[j++] = L[n - 1];
      n = j;
    }

    return n ? L[0] : nullptr;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
