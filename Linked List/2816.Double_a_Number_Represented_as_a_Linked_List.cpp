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

    ListNode* doubleIt(ListNode* head) {
        if (!head) return head;
        reverseList(head);
        int sum = 0;
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            sum += cur->val*2;
            cur->val = sum % 10;
            sum /= 10;
            prev = cur;
            cur = cur->next;
        }
        if (sum) prev->next = new ListNode(sum);
        reverseList(head);
        return head;
    }
};