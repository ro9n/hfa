#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * n1 → … → nk-1 → nk → nk+1 → … → nm → Ø

 * Assume from node nk+1 to nm had been reversed and you are at node nk.

 * n1 → … → nk-1 → nk → nk+1 ← … ← nm

 * We want nk+1’s next node to point to nk.

 * So,

 * nk.next.next = nk;
 * 
 * Be very careful that n1's next must point to Ø. 
 * If you forget about this, your linked list has a cycle in it. 
 * This bug could be caught if you test your code with a linked list of size 2
**/

class Solution {
   public:
    ListNode* reverseList(ListNode* h) {
        if (!h || !h->next) return h;

        ListNode* r = reverseList(h->next);
        h->next->next = h;
        h->next = NULL;
        return r;
    }
};