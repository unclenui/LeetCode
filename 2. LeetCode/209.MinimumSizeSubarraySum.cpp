#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        deque<int> tmp;
        int sum = 0;
        int ans = nums.size()+1;
        for (auto x : nums) {
            tmp.push_back(x);
            sum += x;
            while (sum-tmp.front() >= target) {
                sum -= tmp.front();
                tmp.pop_front();
            }
            if (sum >= target) ans = min(ans, (int)tmp.size());
        }
        return ans == nums.size()+1 ? 0 : ans;
    }
};
