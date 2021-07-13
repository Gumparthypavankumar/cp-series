#include <bits/stdc++.h>

using namespace std;

// For accuracy
const double N = 1e-7;

double findSquareRoot(double n)
{
    double low = 0, high = n, mid;
    while (high - low > N)
    {
        mid = (low + high) / 2;
        if (mid * mid < n)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    double n;
    cin >> n;
    double result = findSquareRoot(n);
    cout << result << "\n";
    return 0;
}