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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head || !nums.size()) return head;
        sort(nums.begin(), nums.end());
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            while (cur && binary_search(nums.begin(), nums.end(), cur->val)) {
                cur = cur->next;

            }
            if (!prev) head = cur;
            else prev->next = cur;
            prev = cur;
            cur = cur ? cur->next : nullptr;
        }
        return head;
    }
};