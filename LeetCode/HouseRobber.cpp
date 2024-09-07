#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            if (i>=3) dp[i] = max(dp[i-3], dp[i-2]) + nums[i];
            else dp[i] = dp[i-2] + nums[i];
        }
        return max(dp[n-1], dp[n-2]);
    }
};