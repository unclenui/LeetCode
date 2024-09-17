#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1 = s1 + ' ';
        s2 = s2 + ' ';
        map<string,int> mp;
        string s;
        for (auto x : s1) {
            if (x == ' ') {
                mp[s]++;
                s = "";
            }
            else s = s + x;
        }
        for (auto x : s2) {
            if (x == ' ') {
                mp[s]++;
                s = "";
            }
            else s = s + x;
        }
        vector<string> ans;
        for (auto x : mp) if (x.second == 1) ans.push_back(x.first);
        return ans;
    }
};