#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *h = head, *p = nullptr;  // head, previous
    while (h) {
      ListNode* n = h->next;  // next
      h->next = p;
      p = h;
      h = n;
    }
    return p;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1), l2 = reverseList(l2);
    int c = 0;  // carry
    ListNode *r = new ListNode(0), *h = r;

    while (l1 || l2 || c) {
      int op1 = l1 ? l1->val : 0;
      int op2 = l2 ? l2->val : 0;
      int sum = op1 + op2 + c;

      if (sum >= 10) {
        h->next = new ListNode(sum - 10);
        c = 1;
      } else {
        h->next = new ListNode(sum);
        c = 0;
      }

      h = h->next;
      l1 = l1 ? l1->next : l1;
      l2 = l2 ? l2->next : l2;
    }

    return reverseList(r->next);
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
