#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> a(n, INT_MAX); 
        int ans = 0;
        a[0] = prices[0];
        for (int i = 1; i < n; i++) {
            a[i] = min(a[i-1], prices[i]);
            ans = max(ans, prices[i]-a[i]);
        }
        return ans;
    }
};


signed main() {
    Solution hehe;
    return 0;
}

