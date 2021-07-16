#include <bits/stdc++.h>

using namespace std;
/*
    Working ex: 
    
    input : [4, 5, 2, 25, 7, 8]
    output: [5, 25, 25, -1, 8, -1]

    Note: Here We operate on indexes so that we can easily access the current element next greatest with that index(confusing right lets go with example)
    initial: 
        stack(st): []
        input: [4, 5, 2, 25, 7, 8]
        ans = []
    iteration 0(i=0):
        st -> empty() so 
        push => st = [0] // 0 is index of element 4
    iteration 1(i=1):
        st -> not empty() so check => input[1] > input[top](i.e here top = 0 => 5 > 4) 
            yes so
            1. set ans of current top element with the current iteration index as greatest(i.e ans[0] = 1)
                    st = [0]
                    ans = [1]
            2. pop 
                    st = []
            stack is empty so
            3. push
                    st = [1]
    iteration 2(i=2):
        st -> not empty() so check => input[2] > input[top](i.e here top = 1 => 2 > 5) 
            No so
            push => st = [1,2] 

    iteration 3(i=3):
        st -> not empty() so check => input[3] > input[top](i.e here top = 2 => 25 > 2) 
            yes so
            1. set ans of current top element with the current iteration index as greatest(i.e ans[2] = 3)
                    st = [1, 2]
                    ans = [1, , 3]
            2. pop 
                    st = [1]
            stack not empty so check => input[3] > input[top](i.e here top = 1 => 25 > 5) 
            yes so
            1. set ans of current top element with the current iteration index as greatest(i.e ans[1] = 3)
                    st = [1]
                    ans = [1, 3, 3]
            2. pop 
                    st = []
            stack is empty so
            3. push
                    st = [3]

    similarly other steps follows at the end the stack remains with some elements for which there are no next greatest so for those indexes we can add -1
    At End: 
    st = [3, 5]
    st.empty() => not empty so 
    1. ans[top] = -1 => ans = [1, 3, 3, -1, 8, ]
    2. pop()
        st = [3]
    st.empty() => not empty so 
    1. ans[top] = -1 => ans = [1, 3, 3, -1, 8, -1]
    2. pop()
        st = []
    empty so All iterations completed
*/

// Next Greater Element using stack
vector<int> NGE(vector<int> v)
{
    vector<int> ans(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }
    vector<int> nge = NGE(v);
    for (auto index : nge)
    {
        cout << (index != -1 ? v[index] : -1) << " ";
    }
    return 0;
}