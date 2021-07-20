#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

int binaryMultiply(long long, long long); // Function Declaration

/*
    In Edge cases where  the range of numbers are 10^18 i.e (a <= 10^18) and (M <= 10^18) b is not considered
    We can not directly multiply since the multiplication can return in overflow  i.e (10^18 * 10^18 = 10^36) which is very huge to store in any data type(except double) but we know that long long can store data upto  2 * 10^18 (which can solve our isseue if we add the numbers like 10^18 + 10^18 = 2 * 10 ^ 18 applying modulo on this can be used) So we add the number b times and apply modulo

    Ex: a * a is similar as 
        a + a + a + --------------------- + atimes
        So using this technique we multiply a but hold on if we need to add a a times then brute force approach will take O(a) complexity to reduce the time complexity we again use binary multiplication which takes O(Log n) to multiply a times

        Brute Force Approach:
        Ex: 3 ^ 13 -> 3 * 13
            3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 + 3 = 39

        Binary Multiplication:
        We take binary number of power b and if we require that bit we add else skip the bit and continue untill you reach zero

        EX: 3 ^ 13 -> 3 * 13 -> 3 * (1101)
           a = 3 -> b&1 -> true -> ans = 0 + 3 = 3 -> a = 3 + 3 = 6 (b = 0110)
           a = 6 -> b&1 -> false -> a = 6 + 6 =12 (b = 0011)
           a = 12 -> b&1 -> true -> ans = 3 + 12 = 15 -> a = 12 + 12 = 24 (b = 0001)
           a = 24 -> b&1 -> true -> ans = 15 + 24 = 39 -> a = 24 + 39 = 63 (b = 0000)  
           break and return ans (i.e 39 which is indeed 3 * 13)
*/
int binaryExp(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = binaryMultiply(ans, a);
        }
        a = binaryMultiply(a, a);
        b >>= 1;
    }
    return ans;
}

int binaryMultiply(long long a, long long b)
{
    int ans = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << binaryExp(a, b) << "\n";
    return 0;
}