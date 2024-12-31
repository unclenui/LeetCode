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
    int listLen(ListNode *head) {
        if (!head) return 0;
        int cnt = 0;
        ListNode *cur = head;
        while (cur) {
            cur = cur->next;
            cnt++;
        }
        return cnt;
    }

    ListNode *findKth(ListNode *head, int k) {
        if (!head) return nullptr;
        ListNode *cur = head;
        for (int i = 1; i < k; i++) {
            if (!cur->next) return nullptr;
            cur = cur->next;
        }
        return cur;
    }

    ListNode *findTail(ListNode *head, ListNode *tail) {
        if (!head || !tail) return nullptr;
        while (head && head->next != tail) head = head->next;
        return head;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        int n = listLen(head);
        int parts = n/k;
        int extras = n%k;
        int cnt = 1;
        for (int i = 0; i < k; i++) {
            ans[i] = findKth(head, cnt);
            cnt += parts + (extras-i>0);
        }
        for (int i = 0; i < k-1; i++) {
            ListNode *k = findTail(ans[i], ans[i+1]);
            if (k) k->next = nullptr;
        }
        return ans;
    }
};