struct listnode {
  int val;
  listnode* next;
  listnode() : val(0), next(nullptr) {}
  listnode(int x) : val(x), next(nullptr) {}
  listnode(int x, listnode* next) : val(x), next(next) {}
};

class solution {
 public:
  listnode* mergetwolists(listnode* list1, listnode* list2) {
    listnode* head = new listnode();

    listnode* cur = head;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        cur->next = list1;
        list1 = list1->next;
      } else {
        cur->next = list2;
        list2 = list2->next;
      }

      cur = cur->next;
    }

    cur->next = (list1 == nullptr ? list2 : list1);

    return head->next;
  }
};