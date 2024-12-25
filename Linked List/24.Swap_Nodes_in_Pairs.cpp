struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *prev = head, *cur = head->next;
        head = cur;
        
        while (cur->next) {
            ListNode *next = cur->next;
            cur->next = prev;
            if (!(next->next)) {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            prev = next;
            cur = next->next;
        }
        if (!cur->next) {
            cur->next = prev;
            prev->next = nullptr;
        }
        return head;
    }
};