#include<bits/stdc++.h>
#define int long long
using namespace std;

int A,K,L,R;
signed main(){
    cin>>A>>K>>L>>R;
    int len=R-L;
    if(len==0){
        if(A==L)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    else{
        int left=A-L;
        int right=R-A;
        int ans=0;
        if(left>=0){
            ans+=left/K;
        }
        if(right>=0){
            ans+=right/K;
        }
        if(L<=A and A<=R)
            cout<<ans+1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
} 
