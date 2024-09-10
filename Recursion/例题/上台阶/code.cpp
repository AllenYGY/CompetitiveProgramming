#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

int a[101]={0};

signed main() {
    a[1]=1;
    a[2]=2;
    a[3]=4;
    int n;
    cin >> n;
    while(n){
        for(int i=4;i<=n;i++){
            a[i]=a[i-1]+a[i-2]+a[i-3];
        }
        cout << a[n] << endl;
        cin >> n;
    }

    return 0;
}