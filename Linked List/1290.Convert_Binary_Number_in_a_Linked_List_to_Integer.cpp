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
    void reverseList(ListNode* &head) {
        ListNode* prev = nullptr, *cur = head;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        int coeff = 1;
        int ans = 0;
        reverseList(head);
        ListNode *cur = head;

        while (cur) {
            ans += coeff*cur->val;
            coeff *= 2;
            cur = cur->next;
        }
        return ans;
    }
};