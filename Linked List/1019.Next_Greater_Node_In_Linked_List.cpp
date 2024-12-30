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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head) return {};
        vector<int> ans;
        ListNode *cur = head, *next = head->next;
        while (cur) {
            next = cur->next;
            while (next && next->val <= cur->val) next = next->next;
            int k = next ? next->val : 0;
            ans.push_back(k);
            cur = cur->next;
        }
        return ans;
    }
};