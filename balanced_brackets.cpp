#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> symbols = {{'}', '{'}, {']', '['}, {')', '('}};

string isBalanced(string s)
{
    stack<char> st;
    for (auto symbol : s)
    {
        if (symbol == '{' || symbol == '(' || symbol == '[')
        {
            st.push(symbol);
        }
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (symbols[symbol] != top)
            {
                return "NO";
            }
        }
    }
    if (st.empty())
        return "YES";
    return "NO";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << "\n";
    }
    return 0;
}