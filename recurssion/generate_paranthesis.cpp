#include <bits/stdc++.h>
using namespace std;
// Problem: Generate Paranthesis
// Problem link: https://leetcode.com/problems/generate-parentheses/
// global array to store result
vector<string> ans;
/*
    Algoritm:
        In every step either choose opening bracket if opening brackets are available
        similarly also choose closing bracket if closing brackets are available but for a pair to be valid every closing bracket must have a opening bracket so check whether the opening brackets are greater than closing here the condition is open < close since the value of open is decreased in all recurssion calls
*/
void generate(string &s, int open, int close) {
    if (open == 0 && close == 0) {
        ans.push_back(s);
        return;
    }
    if (open > 0) {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0) {
        if (open < close) {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    string s;
    generate(s, n, n);
    for (auto value : ans) {
        cout << value << " ";
    }
    return 0;
}