#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> tmp(n);
        tmp[0] = true;
        for (int i = 0; i < n; i++) {
            if (tmp[i] != true) continue;
            if (nums[i] > n-i-1) return true;
            for (int j = 1; j <= nums[i]; j++) {
                tmp[i+j] = true;
            }
        }
        return tmp[n-1];
    }
};