#include <bits/stdc++.h>
using namespace std;

// Declare symbols to avoid extra conditions inside function
unordered_map<char, char> symbols = {{'}', '{'}, {']', '['}, {')', '('}};

string isBalanced(string s) {
    stack<char> st;
    for (auto symbol : s) {
        // Check if bracket is opening
        if (symbol == '{' || symbol == '(' || symbol == '[') {
            st.push(symbol);
        } else {
            /*
                You should return No only when the closing brackets sequence are not matching with opening bracket sequence 
            */
            if (st.empty()) // Edge condition
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[symbol] != top) {
                return "NO";
            }
        }
    }
    if (st.empty())
        return "YES";
    return "NO";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << isBalanced(s) << "\n";
    }
    return 0;
}