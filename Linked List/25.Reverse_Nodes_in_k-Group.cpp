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
    void reverseList(ListNode *&head, ListNode *&tail) {
        if (!head) return;
        tail = head;
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k <= 1) return head;
        ListNode *prev = nullptr, *left = head;
        ListNode *right = head, *next = right->next;
        int cnt = 1;
        while (right) {
            cnt++;
            right = right->next;
            next = next ? next->next : nullptr;
            if (cnt % k == 0) {
                if (right) right->next = nullptr;
                else break;
                reverseList(left, right);
                if (!prev) head = left;
                else prev->next = left;
                right->next = next;
                prev = right;
                left = next;
            }
        }
        return head;
    }
};