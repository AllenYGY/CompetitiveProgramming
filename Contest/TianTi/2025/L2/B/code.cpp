#include<bits/stdc++.h>

#define int long long 
#define endl '\n'

using namespace std;
// [-10, 0] [-20, 1] [-30, 2]
// [50, 0] [75, 1] [100, 2]
// [90, 0] [75, 1] [60, 2]
void solve(){
    int n;cin>>n;
    vector<int> Points0;
    vector<int> Points1;
    vector<int> Points2;

    for( int i=0;i<n;i++){
        int tx,ty;cin>>tx>>ty;
        if(ty==0) Points0.push_back(tx);
        else if (ty==1)  Points1.push_back(tx);
        else if(ty==2)  Points2.push_back(tx);
    }
    // if(Points0.size()!=0 and Points1.size()!=0 and Points2.size()!=0) {
    //     cout<<"["<<Points0[0]<<", "<<"0] ";
    //     cout<<"["<<Points1[0]<<", "<<"1] ";
    //     cout<<"["<<Points1[0]<<", "<<"2]";
    // }else    
    cout<<-1;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}