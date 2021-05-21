#include<bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
long long a[N];// Global array with array elements having default 0

int main(){
    int n,queries;
    cin>>n>>queries;
    while(queries-- > 0){
        int l,r, summand;
        cin>>l>>r>>summand;
        a[l] += summand;
        // Here edge cases are not considered keeping in mind that we have enough space in the array
        a[r+1] -= summand;
    }
    long long maxElement = -1;
    // Pre-computation
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(a[i] > maxElement) maxElement = a[i];
    }
    cout<<maxElement<<"\n";
    return 0;
}

// Time Complexity: O(q) + O(n) + O(n) = O(q) + 2 * O(n) -> O(q+n) in the worst case