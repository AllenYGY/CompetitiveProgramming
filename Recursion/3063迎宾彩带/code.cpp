#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n';
using namespace std;

signed main(){
    int n;
    cin>>n;
    int a[n+1]={0};
    a[1]=2,a[2]=2;
    for(int i=3;i<=n;i++){
        a[i]=a[i-2]+a[i-1];
    }
    cout<<a[n]<<endl;
    return 0;
}
