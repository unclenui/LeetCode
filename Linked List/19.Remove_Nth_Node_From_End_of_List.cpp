struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || n <= 0) return nullptr;
        ListNode *slow = head, *quick = head;
        for (int i = 0; i < n; i++) {
            if (quick) quick = quick->next;
            else return head;
        }
        if (!quick) return head = head->next;
        while (quick->next) {
            quick = quick->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list 