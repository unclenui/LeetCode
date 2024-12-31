/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getTail(ListNode *head) {
        if (!head) return head;
        while (head->next) head = head->next;
        return head;
    }

    int getLen(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode *getKthFromTail(ListNode *head, int k) {
        ListNode *slow = head, *fast = head;
        for (int i = 1; i < k; i++) {
            if (fast) fast = fast->next;
            else return nullptr;
        }
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tailA = getTail(headA), *tailB = getTail(headB);
        if (!tailA || !tailB || tailA != tailB) return nullptr;
        int w = min(getLen(headA), getLen(headB));
        headA = getKthFromTail(headA, w); headB = getKthFromTail(headB, w);
        while (headA != headB && headA && headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;

    }
};