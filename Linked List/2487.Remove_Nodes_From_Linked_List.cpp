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
    void reverseList(ListNode *&head) {
        if (!head) return;
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head) return head;
        reverseList(head);
        int mxm = 0;
        ListNode *cur = head, *next;
        while (cur) {
            mxm = max(mxm, cur->val);
            next = cur->next;
            while (next && next->val < mxm) {
                next = next->next;
            }
            cur = cur->next = next;
        }
        reverseList(head);
        return head;
    }
};