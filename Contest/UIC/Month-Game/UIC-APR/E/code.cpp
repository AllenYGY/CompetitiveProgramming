#include<bits/stdc++.h>
#define int long long

using namespace std;

int T;

void solve(int n,int k){
    vector<int> l(n);
    vector<int> r(n);
    vector<int> b(1000001,0);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        if(l[i]>k or k> r[i]){
            continue;
        }
        if(l[i]>1000000 or r[i]>1000000){
            // continue;
            cout<<"NO"<<endl;
            return;
        }
        b[l[i]] += 1;  
        b[r[i] + 1] -= 1;
    }
    sort(r.begin(),r.end());
    int ans=0;
    int val=-1;
    for(int i = 1;i <= r[r.size()-1]; i++) 
    {
        b[i] += b[i - 1]; 
        if(b[i]>val) 
        {
            ans = i;
            val=b[i];
        }
        
    }
    sort(b.begin(),b.end());
    if(b[b.size()-1]==b[b.size()-2]){
        cout<<"NO"<<endl;
        return;
    }
    if (ans==k){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        solve(n,k);
    }
    return 0;
}