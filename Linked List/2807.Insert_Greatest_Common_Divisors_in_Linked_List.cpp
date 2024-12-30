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
    int GCD(int a, int b) {
        return (a==0) ? b : GCD(b%a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *cur = head, *next = cur->next;
        while (next) {
            cur->next = new ListNode(GCD(cur->val, next->val), next);
            cur = next;
            next = next->next;
        }
        return head;
    }
};