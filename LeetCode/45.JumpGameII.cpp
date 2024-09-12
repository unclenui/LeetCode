#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0x3f3f3f);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j]-(i-j) >= 0) dp[i] = min(dp[j]+1, dp[i]);
            }
        }        
        return dp[n-1];
    }
};
