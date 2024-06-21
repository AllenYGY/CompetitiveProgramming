#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> l;
vector<int> r;
vector<int> v;

signed main(){
    int n,T;
    cin>>n>>T;
    l.resize(n);
    r.resize(n);
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i]>>v[i];
    }
    // Get sum of v
    // int sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=v[i];
    // }
    // for(int i=0;i<n;i++){
    //     int t=l[0];
    //     for(int j=0;j<n;j++){
    //         if()
    //     }
    // }
    sort(v.begin(),v.end());
    int ans=v[0]+v[1]+v[2];
    cout<<ans<<endl;
}