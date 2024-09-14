#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool ok[26] = {};
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        for (char x : allowed) ok[x-'a'] = true;
        int ans = 0;
        for (auto x : words) {
            bool nice = true;
            for (char y : x) if (!ok[y-'a']) nice = false;
            ans += nice; 
        }
        return ans;
    }
};
