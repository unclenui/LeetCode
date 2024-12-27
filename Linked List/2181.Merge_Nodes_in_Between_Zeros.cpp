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
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode *cur = head;
        while (cur) {
            if (cur->val == 0) {
                ListNode *run = cur->next;
                while (run && run->val != 0) {
                    cur->val += run->val;
                    run = run->next;
                }
                cur->next = (run && run->next) ? run : nullptr;
                cur = run;
            }
        }
        return head;
    }
};