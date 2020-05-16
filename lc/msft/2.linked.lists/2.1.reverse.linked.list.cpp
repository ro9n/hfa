#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  ListNode* reverseList(ListNode *head) {
    ListNode *h = head, *p = nullptr;  // head, previous
    while (h) {
      ListNode *n = h->next;  // next
      h->next = p;
      p = h;
      h = n;
    }
    return p;
  }
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};