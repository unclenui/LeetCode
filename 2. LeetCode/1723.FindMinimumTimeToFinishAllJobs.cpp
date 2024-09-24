#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int gietToiPls(vector<int> &sum, vector<vector<int>> &dp, int mask, int cnt) {
        if (cnt == 1) return dp[mask][cnt] = sum[mask];
        if (dp[mask][cnt] != -1) return dp[mask][cnt];
        int ans = INT_MAX;
        for (int new_mask = mask; new_mask > 0; new_mask = (new_mask-1) & mask) {
            for (int split = 1; split < cnt; split++) {
                if (split <= __builtin_popcount(new_mask) && cnt-split <= __builtin_popcount(mask-new_mask)) 
                    ans = min(ans, max(gietToiPls(sum, dp, new_mask, split), gietToiPls(sum, dp, mask-new_mask, cnt-split)));
            }
        }
        return dp[mask][cnt] = ans;
    }


    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum((1<<n), 0);
        vector<vector<int>> dp((1<<n), vector<int>(k+1, -1));
        for(int i = 1; i < (1<<n); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) {
                    sum[i] += jobs[j]; 
                }
            }
        }
        return gietToiPls(sum, dp, (1<<n)-1, k);
    }
};