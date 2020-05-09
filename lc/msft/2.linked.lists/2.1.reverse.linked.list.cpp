#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* from(vector<int> v) {
  ListNode *root = new ListNode(0), *head = root;

  for (int v : v) {
    head->next = new ListNode(v);
    head = head->next;
  }

  return root->next;
}

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* rhead = NULL;
    while (head != NULL) {
      ListNode* next = head->next;
      head->next = rhead;
      rhead = head;
      head = next;
    }
    return rhead;
  }
};

int main() {
  ListNode* test = from(vector<int>{1, 2, 3, 4, 5});
  Solution* s = new Solution();
  test = s->reverseList(test);

  return 0;
}