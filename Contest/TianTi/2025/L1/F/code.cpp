#include<bits/stdc++.h>

#define int long long 
#define endl '\n'

using namespace std;

vector<int> op1(vector<int>& A){
    int L1;cin>>L1;
    vector<int>L;
}

vector<int> op2(vector<int>& A){
    
}

vector<int> op3(vector<int>& A){
    
}

vector<int> operation(vector<int>& A){
    int op;cin>>op;
    vector<int> ans(A.size(),0);
    if(op==1) ans=op1(A);
    else if(op==2) ans=op2(A);
    else if(op==3) ans=op3(A);
    return ans;
}

void solve(){
    int N,M;cin>>N>>M;
    vector<int>A(N,0);
    for(int i=0;i<N;i++)cin>>A[i];
    
    while(M--){
        A=operation(A);
    }
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}