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
    
    ListNode *findMiddleNode(ListNode *head) {
        if (!head) return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void updateList(ListNode *&cur, ListNode *&part, ListNode *&head) {
        cur = cur ? (cur->next = part) : (head = part);
        part = part->next;
    }
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode *leftPart = head, *middleNode = findMiddleNode(head), *rightPart = middleNode->next;
        middleNode->next = nullptr;
        reverseList(rightPart);
        ListNode *cur = nullptr;
        int cnt = 1;
        while (leftPart || rightPart) {
            if (cnt&1 && leftPart) updateList(cur, leftPart, head);
            if (!(cnt&1) && rightPart) updateList(cur, rightPart, head);
            cnt++;
        }
        return;
    }
};