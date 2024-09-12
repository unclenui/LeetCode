#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        s += '#';
        for (int i = 0; i < s.length()-1; i++) {
            switch (s[i]) {
            case 'M':
                ans += 1000;
                break;
            case 'D':
                ans += 500;
                break;
            case 'C':
                ans += 100;
                if (s[i+1] == 'M') {ans += 800; i++;}
                if (s[i+1] == 'D') {ans += 300; i++;}
                break;
            case 'X':
                ans += 10;
                if (s[i+1] == 'C') {ans += 80; i++;}
                if (s[i+1] == 'L') {ans += 30; i++;}
                break;
            case 'L':
                ans += 50;
                break;
            case 'V':
                ans += 5;
                break;
            case 'I':
                ans++;
                if (s[i+1] == 'X') {ans += 8; i++;}
                if (s[i+1] == 'V') {ans += 3; i++;}
                break;
            }
        }  
        return ans;
    }
};