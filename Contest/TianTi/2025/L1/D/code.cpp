#include<bits/stdc++.h>

#define int long long 
#define endl '\n'

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int>bits;
    while(n){
        bits.push_back(n&1);
        n>>=1;
    }
    int ans=1;
    for(int i=0;i<bits.size()-1;i++){
        ans*=2;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}