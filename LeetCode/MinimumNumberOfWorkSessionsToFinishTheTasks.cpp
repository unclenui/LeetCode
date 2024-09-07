#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gietToiPls(vector<int> &sum, vector<int> &dp, int sessionTime, int mask) {
        if (sum[mask] <= sessionTime) return dp[mask] = 1;
        if (dp[mask] != -1) return dp[mask];
        int ans = INT_MAX;
        for (int new_mask = mask; new_mask > 0; new_mask = (new_mask-1) & mask) {
            if (new_mask == mask) continue;
            ans = min(ans, gietToiPls(sum, dp, sessionTime, new_mask)+gietToiPls(sum, dp, sessionTime, mask-new_mask));
        }
        return dp[mask] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> sum((1<<n)), dp((1<<n), -1);
        for (int mask = 0; mask < (1<<n); mask++) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) sum[mask] += tasks[i];
            }
        }
        return gietToiPls(sum, dp, sessionTime, (1<<n)-1);
    }
};