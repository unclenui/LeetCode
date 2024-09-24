#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int product = 1;
        int cnt_zr = 0;
        for (auto x : nums) {
            if (x == 0) cnt_zr++;
            else product *= x;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) ans[i] = cnt_zr > 1 ? 0 : product;
            else ans[i] = cnt_zr ? 0 : product/nums[i];
        }
        return ans;
    }
};