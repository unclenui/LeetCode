#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += (s[i]-'a'+1)%10 + ((s[i]-'a'+1)/10)%10;
        }

        for (int i = 2; i <= k; i++) {
            int tmp = 0;
            while (ans > 0) {
                tmp += ans%10;
                ans /= 10;
            }
            ans = tmp;
        }
        return ans;
    }
};