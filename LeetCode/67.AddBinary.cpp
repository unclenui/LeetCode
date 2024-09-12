#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) swap(a,b);
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        bool remain = false;
        while (i+1 && j+1) {
            if (a[i] == '1' && b[j] == '1') {
                if (remain) ans = ans + '1';
                else ans = ans + '0';
                remain = true;
            }
            else 
            if (a[i] == '1' || b[j] == '1') {
                if (remain) ans = ans + '0';
                else ans = ans + '1';
            }
            else {
                if (remain) { ans = ans + '1'; remain = false; }
                else ans = ans + '0';
            }
            i--; j--;
        } 

        while (i+1) {
            if (a[i] == '1') {
                if (remain) ans = ans + '0';
                else ans = ans + '1';
            }
            else {
                if (remain) { ans = ans + '1'; remain = false; }
                else ans = ans + '0';
            }
            i--;
        }
        if (remain) ans = ans + '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
