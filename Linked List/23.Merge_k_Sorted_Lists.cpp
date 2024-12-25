#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void update(ListNode *&l, ListNode *&cur, ListNode *&head) {
        if (!cur) head = cur  = new ListNode(l->val); 
        else cur = cur->next = new ListNode(l->val);
        l = l->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr, *cur = nullptr;
        int index;
        do {
            index = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i]) {
                    if (index == -1) index = i;
                    else index = (lists[index]->val >= lists[i]->val ? i : index);
                }
            }
            if (index != -1) update(lists[index], cur, head);
        } while(index != -1);     
        return head;
    }
};
//https://leetcode.com/problems/merge-k-sorted-lists/?envType=problem-list-v2&envId=linked-list