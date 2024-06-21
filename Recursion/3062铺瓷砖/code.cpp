#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n';
using namespace std;

const int MOD=12345;

int f(int n){
    if(n==1) return 1;
    if(n==2) return 3;
    return f(n-1)+2*f(n-2);
}

signed main(){
    int n;
    cin>>n;
    int d[n+1];
    d[0]=0,d[1]=1,d[2]=3;
    for(int i=3;i<=n;i++){
        d[i]=(d[i-1]+2*d[i-2])%MOD;
    }
    cout<<d[n]<<endl;
    return 0;
}
