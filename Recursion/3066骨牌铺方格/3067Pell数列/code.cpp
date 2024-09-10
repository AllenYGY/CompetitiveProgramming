#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

int a[1000001]={0};

void solve(int n){

    a[1]=1;
    a[2]=2;
    for(int i=3;i<=n;i++){
        a[i]=(2*a[i-1]+a[i-2])%32767;
    }
}

signed main() {
    int T=0;
    cin>>T;
    while(T--){
        int n=0;
        cin>>n;
        if(a[n]!=0)
            cout<<a[n]<<endl;
        else{
            solve(n);
            cout<<a[n]<<endl;
        }
    }
    return 0;
}