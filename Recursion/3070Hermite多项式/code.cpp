#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;

double h(double x, int n){
    if(n==0) return 1;
    if(n==1) return 2*x;
    return 2*x*h(x,n-1)-2*(n-1)*h(x,n-2);
}

signed main() {
    int n;
    double x;
    cin>>n>>x;
    cout<<fixed<<setprecision(2)<<h(x,n)<<endl;
    return 0;
}