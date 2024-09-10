#include<bits/stdc++.h>
#include<iostream>
#define int long long
#define endl '\n'
using namespace std;


double f(double x, int n){
    if(n==1) return sqrt(1+x);
    return sqrt(n+f(x,n-1));
}

signed main() {
    double x; 
    int n;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<f(x,n)<<endl;
    return 0;
}