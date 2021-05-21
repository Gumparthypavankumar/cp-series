/* 
    This Question is based on pre computation technique
    Follow This link for tutorial: https://www.youtube.com/watch?v=e3qhRh4UOug&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=21 
    Problem link: https://www.codechef.com/problems/GCDQ
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        * we will use inbuilt gcd algorithm for efficient computation
    */
    int T;
    cin>>T;
    while(T-- > 0){
        int n,Q;
        cin>>n>>Q;
        int GCDForward[n+10];
        int GCDBackward[n+10];
        int a[n+10];
        GCDForward[0] = GCDBackward[n+1] = 0;
        a[0] =0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            GCDForward[i] = __gcd(GCDForward[i-1],a[i]);
        }
        for(int i=n;i>=1;i--){
            GCDBackward[i] = __gcd(GCDBackward[i+1],a[i]);
        }
        while(Q--){
            int L,R;
            cin>>L>>R;
            cout<<__gcd(GCDForward[L-1],GCDBackward[R+1])<<"\n";
        }
    }
	return 0;
}
