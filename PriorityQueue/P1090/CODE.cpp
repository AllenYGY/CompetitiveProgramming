#include<bits/stdc++.h>
#include<queue>
#include<iostream>
#define int long long 
#define endl '\n';

using namespace std; 

priority_queue<int,vector<int>, greater<int>> q;

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        q.push(x);
    }
    int ans=0;
    while(q.size()>1){
        int t1 =q.top(); q.pop();
        int t2 =q.top(); q.pop();
        ans+= (t1+t2);
        q.push(t1+t2);
    }
    cout<<ans<<endl;

}

signed main(){
    solve();
    return 0;
}



