#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int GCD(int a, int b) {
        return b ? GCD(b, a%b) : a;
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < i; j++) {
                int tmp = nums[j];
                while (tmp >= 10) tmp /= 10;
                ans += (GCD(nums[i]%10, tmp )==1);
            }
        return ans;
    }
};
