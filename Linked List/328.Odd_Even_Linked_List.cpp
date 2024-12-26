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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next;
        ListNode *feven = head->next;
        while (even) {
            ListNode *next = even->next;
            if (!next) {
                odd->next = feven;
                even->next = nullptr;
                return head;
            }

            odd = odd->next = next;
            even = even->next = next->next;
        }
        odd->next = feven;
        return head;
    }
};