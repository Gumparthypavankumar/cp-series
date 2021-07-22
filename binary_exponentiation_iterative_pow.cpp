#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

/*
    Algorithm:
     Consider Binary number of b and divide until you reach zero

    3^3 = 3^011 (i.e Binary of 3 is 011)

    011 -> 2 + 1 -> 3^2 + 3^1 => 3^3 = 27

    if LSB is odd multiply answer with a
    else Multiply a with itself and Divide b

    3 != 0 (b = 011)
    3 & 1 -> true => ans = 1 * 3 = 3
                     a = 3 * 3 = 9
                     b = 01 (2)
    2 & 1 -> true => ans = 3 * 9 = 27
                     a = 9 * 3 = 27
                     b = 0(0)
    0 & 1 -> false So answer is 27
*/
int binaryExponentiation(int a, int b) {
    int ans = 1;
    while (b != 0) {
        if (b & 1) {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << binaryExponentiation(a, b) << endl;
    return 0;
}