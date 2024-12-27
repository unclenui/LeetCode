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
    ListNode* kthNodefromTail(ListNode *head, int k) {
        if (!head) return nullptr;
        ListNode *slow = head, *fast = head;
        for (int i = 1; i < k; i++) {
            if (fast->next) fast = fast->next;
            else return nullptr;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode* kthNodefromHead(ListNode *head, int k) {
        if (!head) return nullptr;
        ListNode *cur = head;
        for (int i = 1; i < k; i++) {
            if (cur->next) cur = cur->next;
            else return nullptr;
        }
        return cur;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode *kfh = kthNodefromHead(head, k);
        ListNode *kft = kthNodefromTail(head, k);
        if (!kfh) return head;//kft aswell;    
        int tmp = kfh->val;
        kfh->val = kft->val; 
        kft->val = tmp;  
        return head;
    }
};