#include<bits/stdc++.h>

#define int long long 
#define endl '\n'

using namespace std;


void solve(){
    int n;cin>>n;
    vector<string> sf(n,"");
    for(int i=0;i<n;i++)cin>>sf[i];
    if(n<500) cout<<n/2+1<<endl;
    else cout<<n/2<<endl;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}