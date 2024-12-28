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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        ListNode *upd = nullptr;
        while (cur) {
            if ((!prev || (prev && prev->val != cur->val)) && (!next || (next && next->val != cur->val))) {
                if (!upd) head = upd = cur;
                else upd = upd->next = cur;
            }
            prev = cur;
            cur = next;
            next = next ? next->next : nullptr;
        }
        if (upd) {
            upd->next = nullptr;
            return head;
        }
        else return nullptr;
    }
};