#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(-1, head);
    auto prev = dummy;

    while (prev->next) {
      auto cur = prev->next;
      if (cur->val == val) {
        prev->next = cur->next;

        delete cur;
      } else {
        prev = cur;
      }
    }

    ListNode* resNode = dummy->next;

    delete dummy;

    return resNode;
  }
};