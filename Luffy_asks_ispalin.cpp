#include<bits/stdc++.h>
using namespace std;
// Problem Link: https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/ispalin/

const int N = 1e5+10;
int charFrequency[N][26];

int main(){
    int t;
    cin>>t;
    while(t-- > 0){
        for(int i=0;i<N;i++){
            for(int j=0;j<26;j++){
                charFrequency[i][j] = 0;
            }
        }
        int n,q;
        string s;
        cin>>n>>q>>s;
        for(int i=0;i<n;i++){
            charFrequency[i+1][s[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                charFrequency[j][i] += charFrequency[j-1][i];
            }
        }
        while(q-- > 0){
            int l,r;
            cin>>l>>r;
            int oddCount = 0;
            for(int i=0;i<26;i++){
                int charCt = charFrequency[r][i] - charFrequency[l-1][i];
                if(charCt%2 != 0) oddCount++;
            }
            if(oddCount > 1) cout<<"NO"<<"\n";
            else cout<<"YES"<<"\n";
        }
    }
    return 0;
}