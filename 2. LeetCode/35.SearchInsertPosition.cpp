#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size()-1] < target) return nums.size();
        if (nums[0] > target) return 0;
        int l = 0, r = nums.size()-1, mid;
        while (l < r-1) {
            mid = (l+r)/2;
            if (target > nums[mid]) l = mid;
            else r = mid;
        } 
        if (nums[l] == target) return l;
        return r;
    }
};