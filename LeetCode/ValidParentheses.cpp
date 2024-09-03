#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isOpen(char x) {
        if ((x == '{') || (x == '[') || (x == '(')) return true;
        return false;
    }
    int val(char x) {
        if (x == '{' || x == '}') return 1;
        if (x == '[' || x == ']') return 2;
        return 3;

    }
    bool isValid(string s) {
        stack<char> x;
        for (int i = 0; i < s.length(); i++) {
            if (isOpen(s[i])) x.push(s[i]);
            else 
            if (!x.empty() && !isOpen(s[i]) && val(s[i]) == val(x.top())) x.pop();
            else return false;
        }      
        return (x.size()) ? false : true;
    }
};