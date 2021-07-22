#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
int n;
long long m;
int trees[N];

/*
    Problem link: https://www.spoj.com/problems/EKO/
    Approach: 
        Since the range from 0 to N is monotonic we can use Binary search
        NOTE: We are considering 0 since the trees can be cut from ground level
        For every H we need to check whether this H is less than or equal to Tree height because only then we can cut the tree
        mid is what we are passing as height in every iteration
*/

bool isWoodSufficient(int height)
{
    long long wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (trees[i] >= height)
        {
            wood += (trees[i] - height);
        }
    }
    return wood >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    int low = 0, high = 1e9, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (isWoodSufficient(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (isWoodSufficient(high))
    {
        cout << high << endl;
    }
    else
    {
        cout << low << endl;
    }
    return 0;
}