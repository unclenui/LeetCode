struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void isGood(ListNode *&l, int &rem) {
        if (!l) return;
        rem += l->val;
        l = l->next;
    }
    
    void update(ListNode *&cur, ListNode *&head, int data) {
        if (!cur) head = cur = new ListNode(data);
        else cur = cur->next = new ListNode(data);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr, *cur = nullptr;
        int sum = 0;
        do {
            isGood(l1, sum);
            isGood(l2, sum);
            update(cur, ans, sum%10);
            sum/=10;
        } while(l1 || l2 || sum);
        return ans;
    }
};