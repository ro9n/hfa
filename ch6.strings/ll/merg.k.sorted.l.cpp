#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
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

    ListNode* mergeKLists(vector<ListNode*>& l) {
        if (l.empty()) return NULL;

        int n = l.size();

        while (n > 1) {
            int j = 0;
            for (int i = 0; i + 1 < n; i += 2) {
                l[j++] = merge(l[i], l[i + 1]);
            }
            if (n & 1) l[j++] = l[n - 1];
            n = j;
        }

        return l[0];
    }
};
