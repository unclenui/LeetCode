#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int d[(1<<16)];
    int sum = 0;
    int dp[(1<<16)][16];
public:
    bool magic(int mask, int i, int k, int n) {
        if (i==k) return true;
        if (dp[mask][i] != -1) return dp[mask][i];
        bool ans = 0;
        int r_mask = ((1<<n)-1)^mask;
        for (int n_mask = r_mask; n_mask > 0; n_mask = (n_mask-1) & r_mask) {
            if (d[n_mask] == sum/k) ans |= magic(mask | n_mask, i+1, k, n);
        }
        return dp[mask][i] = ans;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        for (auto x: nums) sum += x;
        memset(dp,-1,sizeof(dp));
        for (int mask = 0; mask < (1<<nums.size()); mask++) {
            for (int i = 0; i < nums.size(); i++) {
                if (mask & (1<<i)) d[mask] += nums[i];
            }
        }
        return (sum%k) ? false : magic(0, 0, k, nums.size());
    }
};
