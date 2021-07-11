#include <bits/stdc++.h>

using namespace std;

long long findGCD(long long a, long long b)
{
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
vector<long long> lcmAndGcd(long long A, long long B)
{
    vector<long long> ans;
    long long result = findGCD(A, B);
    ans.push_back((A * B) / result);
    ans.push_back(result);
    return ans;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    vector<long long> result = lcmAndGcd(a, b);
    cout << "LCM is : " << result[0] << "\n"
         << "GCD is : " << result[1] << "\n";
    return 0;
}