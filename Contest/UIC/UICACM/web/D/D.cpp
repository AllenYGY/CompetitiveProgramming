#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N,M,T;
  cin>>N>>M>>T;
  int A[N+1],B[N+1];
  memset(B,0,sizeof(B));
  memset(A,0,sizeof(A));
  int x,y;
  for(int i=1;i<N;i++) cin>>A[i];
  for(int i=1;i<M+1;i++) {
    cin>>x>>y;
    B[x]=y;
  }
  // cout<<B[1]<<" "<<B[1]<<endl;
  for(int i=1;i<N;i++){
    T+=B[i];
    // if(T<=0){cout<<"No"<<endl;return 0;}
    T-=A[i];
    if(T<=0){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}
