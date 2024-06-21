#include<bits/stdc++.h>
#include<iostream>

#define int long long
#define endl '\n'

using namespace std;

signed main(){
    int n=0;
    cin>>n;
    int dp[52];   
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    cout<<dp[n]<<endl;
    return 0;
}
