#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
/*
    Binary Exponentiation is generally used to calculate pow of a number i.e a^n in O(log (n)) complexity instead of O(n) using naive approach 
    The algorithm:
    1. if power is even then divide by 2 until you reach zero
    2. if power is odd split the number and divide the other part until you reach zero

    EX: 2^16 => 16 is even
        2^16 = 2^8 * 2^8
        2^8 = 2^4 * 2^4
        2^4 = 2^2 * 2^2
        2^2 = 2^1 * 2^1
        2^1 = 2 * 2^0 (1 is odd) when you reach to zero return 1 

        // When odd
        3^7 = 3 * 3^6
        3^6 = 3^3 * 3^3
        3^3 = 3 * 3^2
        3^2 = 3^1 * 3^1 
        3^1 = 3 * 3^0 when you reach return 1
*/

int binaryExponentiation(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int res = binaryExponentiation(a, b / 2);
    // check if power is odd
    if (b & 1)
    {
        return (a * ((res * 1LL * res) % M)) % M; // 1LL represent long number since the (int * int) may result in large number which might lead to overflows long long will be able to handle
    }
    return (res * res) % M;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int result = binaryExponentiation(a, b);
    cout << result << "\n";
    return 0;
}