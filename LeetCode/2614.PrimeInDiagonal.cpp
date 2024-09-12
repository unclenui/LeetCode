#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPrime(int x) {
        if (x <= 1) return false;
        for (int i = 2; i <= sqrt(x); i++) if (x%i==0) return false;
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) 
            if (isPrime(nums[i][i])) ans = max(ans,nums[i][i]);
        for (int i = 0; i < nums.size(); i++) 
            if (isPrime(nums[i][nums.size()-1-i])) ans = max(ans, nums[i][nums.size()-1-i]);
        return ans;
    }
};