#include <bits/stdc++.h>
using namespace std;

int digitSum(int num){
    if(num == 0) return 0;
    return num%10 + digitSum(num/10);
}

int arraySum(int a[], int n){
    if(n < 0) return 0;
    return arraySum(a, n-1) + a[n];
}
int main(){
    int a[] =  {1,2,3};
    cout<<"ArraySum : "<<arraySum(a, 2)<<"\n";
    cout<<"Digit sum for 123 is : "<< digitSum(123)<<"\n";
    return 0;
}