#include <bits/stdc++.h>

using namespace std;
/*

*/
long long findGCD(long long a, long long b) {
    /*
        using continous division
        Ex: 6)12(2
              12
            =  0 => 6 -> ans  
    */
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

vector<long long> lcmAndGcd(long long A, long long B) {
    vector<long long> ans;
    /*
        LCM of 2 numbers is product of numbers divided with gcd of that 2 numbers
    */
    long long result = findGCD(A, B);
    ans.push_back((A * B) / result);
    ans.push_back(result);
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;
    vector<long long> result = lcmAndGcd(a, b);
    cout << "LCM is : " << result[0] << "\n"
         << "GCD is : " << result[1] << "\n";
    return 0;
}