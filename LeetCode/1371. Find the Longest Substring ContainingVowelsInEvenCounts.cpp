#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    pair<int,int> bits[(1<<5)];
    char c[5] = {'a', 'e', 'i', 'o', 'u'};
public:
    int isVowel(char x) {
        for (int i = 0; i < 5; i++) if (c[i] == x) return (1<<i);
        return -1;
    }
    int findTheLongestSubstring(string s) {
        for (auto &x : bits) {
            x.first = INT_MAX;
            x.second = INT_MIN;
        }
        int tmp = 0;
        bits[0] = {0, INT_MIN};
        for (int i = 0; i < s.size(); i++) {
            int srp = isVowel(s[i]);
            if (srp != -1) {
                if (tmp & srp) tmp -= srp;
                    else tmp |= srp;    
            }
            bits[tmp].first = min(bits[tmp].first, i+1);
            bits[tmp].second = max(bits[tmp].second, i+1);
        }
        int ans = 0;
        for (auto &x : bits) {
            if (x.first != INT_MAX || x.second != INT_MIN) ans = max(ans,x.second-x.first);
        }
        return ans;
    }
};