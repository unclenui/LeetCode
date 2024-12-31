/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *findKth(ListNode *head, int k) {
        if (!head) return nullptr;
        ListNode *cur = head;
        for (int i = 1; i < k; i++) {
            if (cur->next) cur = cur->next;
            else return nullptr;
        }
        return cur;
    }

    ListNode *findTail(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *cur = head;
        while (cur->next) cur = cur->next;
        return cur;
    }

    void deleteList(ListNode *&head, ListNode *tail) {
        ListNode *next, *cur = head;
        while (cur && cur != tail) {
            next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
    }

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (!list1 || !list2 || a <= 0 || b <= 0) return nullptr;
        ListNode *left = findKth(list1, a), *right = findKth(list1, b+2);
        deleteList(left->next, right);
        ListNode *l2Tail = findTail(list2);
        left->next = list2;
        l2Tail->next = right;
        return list1;
    }
};