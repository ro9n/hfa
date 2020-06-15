#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = 0, c = 0;
        ListNode* d = new ListNode(0);
        ListNode* r = d;
        while (l1 || l2) {
            int a = l1 ? l1->val : 0, b = l2 ? l2->val : 0;
            s = a + b + c, c = s / 10, s %= 10;
            r->next = new ListNode(s), r = r->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (c) r->next = new ListNode(c);
        return d->next;
    }
};