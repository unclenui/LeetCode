#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dp[(1<<12)][12][12] = {};
    int vui(int x) {
        int ans = 1;
        for (int i = 2; i <= x; i++) ans *= i;
        return ans;
    }
public:
    int magic(vector<int>& nums, int mask, int prev, int i) {
        if (i == nums.size()) return 1;
        if (dp[mask][prev][i] != -1) return dp[mask][prev][i];
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if ((!(mask & (1<<j)) && pow((int)sqrt(nums[j]+nums[prev]),2) == nums[j]+nums[prev])) ans += magic(nums, mask | (1<<j), j, i+1);
        }
        return dp[mask][prev][i] = ans;
    }
    int numSquarefulPerms(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += magic(nums, (1<<i), i, 1);
        }
        sort(nums.begin(), nums.end());
        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                ans /= vui(c);
                c = 0;
            }
            c++;
        }
        return ans/vui(c);
    }
};