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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        while (cur) {
            while (cur && cur->val == val) {
                if (!prev) head = next;
                else prev->next = next;
                cur = next;
                next = next ? next->next : nullptr;
            }
            prev = head == next ? nullptr : cur;
            cur = next;
            next = next ? next->next : nullptr;
        }
        return head;
    }
};