#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

int a[51]={0};

signed main() {
    a[1]=1, a[2]=2;
    int n=0;
    while(cin>>n){
        for(int i=3;i<=n;i++){
            a[i]=a[i-1]+a[i-2];
        }
        cout << a[n] << endl;
    }
    return 0;
}

