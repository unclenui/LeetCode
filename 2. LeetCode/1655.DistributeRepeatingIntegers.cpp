#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n = 0, m = 0;
    int cnt[1001] = {}, dq[1<<10] = {};
    int dp[(1<<10)][1001];
public:
    void init(vector<int>& nums, vector<int>& quantity) {
        m = quantity.size();
        for(auto x : nums) cnt[x]++;
        sort(cnt, cnt+1001, greater<int>());
        while(cnt[n]) n++;

        memset(dp,-1,sizeof(dp));
        for (int mask = 0; mask < (1<<m); mask++) for (int i = 0; i < m; i++)
            if (mask & (1<<i)) dq[mask] += quantity[i];
    }

    bool magic(int mask, int i) {
        if (mask == (1<<m)-1) return true;
        if (i == n) return false;
        if (dp[mask][i] != -1) return dp[mask][i];

        bool ans = false;
        int r_mask = ((1<<m)-1)-mask;
        for (int n_mask = r_mask; n_mask > 0; n_mask = (n_mask-1) & r_mask) {
            if (dq[n_mask] <= cnt[i]) ans |= magic(mask | n_mask, i+1);
        }
        return dp[mask][i] = ans;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        init(nums, quantity);
        return magic(0,0);
    }
};