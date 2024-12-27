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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans{-1, -1};
        if (!head || !head->next) return ans;
        ListNode *prev = nullptr, *cur = head, *next = head->next;
        int newIndex = 0, oldIndex = 0; 
        int cnt = 1;
        while (next) {
            if (prev) {
                if ((prev->val > cur->val && cur->val < next->val) || 
                    (prev->val < cur->val && cur->val > next->val)) {
                    if (newIndex) ans[0] = (ans[0] != -1 ? std::min(ans[0],cnt-newIndex) : cnt-newIndex);
                    if (oldIndex) ans[1] = (ans[1] != -1 ? std::max(ans[1],cnt-oldIndex) : cnt-oldIndex);
                    newIndex = cnt;
                    oldIndex = (oldIndex ? oldIndex : cnt);
                }
            }
            prev = cur;
            cur = next;
            next = next->next;
            cnt++;
        }
        return ans;
    }
};