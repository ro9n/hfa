#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* d = new ListNode(0);
        ListNode* r = d;

        while (l1 || l2) {
            if (!l1)
                r->next = l2, l2 = NULL;
            else if (!l2)
                r->next = l1, l1 = NULL;
            else {
                if (l1->val < l2->val)
                    r->next = new ListNode(l1->val), l1 = l1->next;
                else
                    r->next = new ListNode(l2->val), l2 = l2->next;
                r = r->next;
            }
        }

        return d->next;
    }
};