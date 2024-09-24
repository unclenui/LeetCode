#include<bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
    string tmp1 = a + b;
    string tmp2 = b + a;
    return tmp1 > tmp2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            str[i] = to_string(nums[i]);
        }
        sort(str.begin(), str.end(), cmp);
        for (auto x : str) cout << x << ' ';
        string ans = "";
        ans = accumulate(str.begin(), str.end(), ans);
        
        return ans[0]=='0'? "0" : ans;
    }
};