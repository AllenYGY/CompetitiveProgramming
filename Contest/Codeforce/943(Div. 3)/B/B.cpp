#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int lp=0;
    int ans=0;
    for(int i=0;i<a.size();i++){
        bool flag=false;
        for(int j=lp;j<b.size();j++){
            if(a[i]==b[j]){
                lp=j+1;
                flag=true;
                ans++;
                break;
            }
        }
        if(!flag){
            break;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

