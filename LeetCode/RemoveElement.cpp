#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (auto x : nums) cnt += val!=x;         
        int j = nums.size()-1;
        for (int i = 0; i < cnt; i++) {
            while (nums[j] == val) j--;
            if (nums[i] == val) swap(nums[i], nums[j]);
        }
        return cnt;
    }
};