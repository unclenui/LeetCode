
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getNode(ListNode *head, int k) {
        if (!head || k <= 0) return nullptr;
        ListNode *cur = head;
        for (int i = 1; i < k; i++) {
            if (cur) cur = cur->next;
            else return nullptr;
        }
        return cur;
    }

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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return head;
        ListNode *prev = getNode(head, left-1);
        ListNode *slow = getNode(head, left);
        ListNode *fast = getNode(head, right);
        ListNode *next = fast->next;
        fast->next = nullptr;
        reverseList(slow, fast);
        if (prev) prev->next = slow;
        else head = slow;
        fast->next = next;
        return head;
    }
};