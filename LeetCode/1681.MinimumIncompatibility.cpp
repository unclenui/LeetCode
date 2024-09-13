#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int diff[(1<<16)], ok[(1<<16)] = {}, bits[(1<<16)] = {};
    int dp[(1<<16)][16][23];
    int m = 0;
public:
    void init(vector<int>& nums, int k) {
        for (int mask = 1; mask < (1 << nums.size()); mask++) {
            int save = 0;
            int minb = INT_MAX;
            int maxb = INT_MIN;
            ok[mask] = (__builtin_popcount(mask) == nums.size()/k); 
            for (int i = 0; i < nums.size(); i++) {
                if (mask & (1<<i)) {
                    if (save & (1<<nums[i])) {ok[mask] = false; i = nums.size() + 9;  continue;}
                    save |= (1<<nums[i]); 
                    minb = min(minb, nums[i]);
                    maxb = max(maxb, nums[i]);
                }
            }
            if (ok[mask]) {
                bits[m] = mask;
                diff[m] = maxb-minb;
                m++;
            }
        }
    }

    int magic(int mask, int i, int spot, int k, int n) {
        if (i == k) return spot;
        if (dp[mask][i][spot] != -1) return dp[mask][i][spot];
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            if ((mask&bits[j]) == 0) {
                if (spot + diff[j] <= 22) ans = min(ans, magic(mask|bits[j], i+1, spot + diff[j], k, n));
            }
        }
        return dp[mask][i][spot] = ans;
    }
    int minimumIncompatibility(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return -1;
        init(nums, k);
        memset(dp,-1,sizeof(dp));
        int ans = magic(0, 0, 0, k, nums.size());
        return ans == INT_MAX ? -1 : ans;
    }
};