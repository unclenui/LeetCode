#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = 0;
        for (auto x : nums) target = max(target, x);

        int cnt = 1;
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i-1] == target) ans = max(ans, cnt);
                cnt = 0;
            }
            cnt++;
        }
        return max(ans, nums[nums.size()-1] == target ? cnt : 0);
    }
};