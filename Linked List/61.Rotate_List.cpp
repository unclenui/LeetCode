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
    ListNode* getTail(ListNode *head) {
        if (!head) return nullptr;
        ListNode *ans = head;
        while (ans->next) ans = ans->next;
        return ans;
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

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        reverseList(head);
        ListNode *tail = getTail(head);    
        tail->next = head;
        ListNode *curHead = head;
        for (int i = 1; i <= k; i++) curHead = curHead->next;
        head = curHead;
        while (curHead->next != head) curHead = curHead->next;
        curHead->next = nullptr;
        reverseList(head);
        return head;
    }
};