#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(){
    int n,k;
    cin >>n>>k;
    int ans=n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        int num=0; cin >> num;
        mp[num]++;
        if(mp[num]>=k){
            ans=k-1;
        }
    }
    cout<<ans<< endl;
}

int main(){
    int T=0;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}