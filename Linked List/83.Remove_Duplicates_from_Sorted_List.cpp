struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *slow = head, *fast = head;
        while (fast) {
            if (slow->val == fast->val) fast = fast->next;
            else slow = slow->next = fast;
        }
        slow->next = nullptr;
        return head;
    }
};