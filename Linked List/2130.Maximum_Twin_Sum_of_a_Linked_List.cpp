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
    ListNode *findMiddle(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

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

    int pairSum(ListNode* head) {
        if (!head || !head->next) return 0;
        ListNode *mid = findMiddle(head);
        reverseList(mid);
        ListNode *left = head;
        int ans = 0;
        while (mid) {
            ans = max(ans, left->val + mid->val);
            left = left->next;
            mid = mid->next;
        }
        return ans;
    }
};