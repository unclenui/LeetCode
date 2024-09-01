#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        string s = "";
        while (x > 0) {
            s += (char)(x%10+(int)'0');
            x/=10;
        }
        for (int i = 0; i <= (s.length()-1)/2; i++) 
            if (s[i] != s[s.length()-1-i]) return false;
        return true;
    }
};

signed main() {
    Solution hehe;
    cout << hehe.isPalindrome(0);
}

