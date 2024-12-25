// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void update(ListNode *&l, ListNode *&cur, ListNode *&head) {
        if (!cur) head = cur = new ListNode(l->val);
        else cur = cur->next = new ListNode(l->val);
        l = l->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, *cur = nullptr;
        while (list1 || list2) {
            if (!list1 || (list1 && list2 && list1->val >= list2->val)) update(list2, cur, head);
            else if (!list2 || (list1 && list2 && list2->val >= list1->val)) update(list1, cur, head);
        }
        return head;
    }
};
//https://leetcode.com/problems/merge-two-sorted-lists/?envType=problem-list-v2&envId=linked-list