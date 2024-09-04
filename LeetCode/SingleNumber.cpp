#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        nums.push_back(40000);
        for (int i = 1; i < n; i++) 
            if (nums[i] != nums[i-1]  && nums[i] != nums[i+1]) return nums[i];
        return nums[0];
    }
};