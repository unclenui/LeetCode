#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (deck[i]!=deck[i-1]) break;
            cnt++;
        }
        if (cnt == 1) return false;
        int newcnt = 1;
        for (int i = 1; i < n; i++) {
            if (deck[i]!=deck[i-1]) {
                cnt = gcd(cnt, newcnt);
                newcnt = 0; 
            }
            newcnt++;
        }
        cnt = gcd(cnt, newcnt);
        return cnt>1;
    }
};