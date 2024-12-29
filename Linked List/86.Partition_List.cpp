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
    void update(ListNode *&head, ListNode *&cur, ListNode *in) {
        if (!head) head = cur = in;
        else cur = cur->next = in;
    }

    ListNode* partition(ListNode* head, int x) {
        if (!head) return nullptr;
        ListNode *left = nullptr, *right = nullptr;
        ListNode *curl = nullptr, *curr = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            if (cur->val < x) update(left, curl, cur);
            else update(right, curr, cur);
            cur = cur->next;
        }
        if (curr) curr->next = nullptr;
        if (left) {
            curl->next = right;
            return head = left;
        }
        else {
            return head = right;
        }
    }
};