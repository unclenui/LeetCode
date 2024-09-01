#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < nums.size(); i++) {
            if (binary_search(sorted.begin(), sorted.end(), target - nums[i])) {
                for (int j = 0; j < sorted.size(); j++) {
                    if (i != j && nums[i] + nums[j] == target) return {i,j};
                }
            }
        }
        return {0,0};
    }
};