#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        while (s[n-1] == ' ') n--;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == ' ') return n-1-i;
        }
        return n;
    }
};