#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[(1<<14)][14][14];
    int mod = 1e9+7;
public:
    int magic(int mask, int prev, int i, vector<int>& nums) {
        if (i == nums.size()) return 1;
        if (dp[mask][prev][i] != -1) return dp[mask][prev][i];
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (!i) ans += magic(mask | (1<<j), j, i+1, nums);
            else
            if (!(mask & (1<<j)) && max(nums[prev],nums[j])%min(nums[prev],nums[j])==0) 
            ans += magic(mask | (1<<j), j, i+1, nums);
        }
        return dp[mask][prev][i] = ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return magic(0,0,0,nums);
    }
};