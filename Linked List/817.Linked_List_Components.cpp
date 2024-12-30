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
    int numComponents(ListNode* head, vector<int>& nums) {
        if (!head) return 0; 
        sort(nums.begin(), nums.end());
        ListNode *cur = head;
        int cnt = 0;
        while (cur) {
            bool ok = false;
            while (cur && binary_search(nums.begin(), nums.end(), cur->val)) {
                ok = true;
                cur = cur->next;
            }
            cur = cur ? cur->next : nullptr;
            cnt += ok;
        }
        return cnt;
    }
};