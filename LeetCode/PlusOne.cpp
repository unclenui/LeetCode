#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        bool exist = true;
        for (int i = n-1; i >= 0; i--) {
            digits[i] += exist;
            if (digits[i] == 10) {digits[i] = 0; exist = true;}
            else exist = false;
        }
        vector<int> ans;
        if (exist) ans.push_back(1);
        for (auto x : digits) ans.push_back(x);
        return ans;
    }
};