#include<bits/stdc++.h>

#define int long long 
#define endl '\n'

using namespace std;

int binarysearch(int l,int r,int che){
    int mid=0;
    while(l<=r){
        mid = l+ (r-l)/2;
        if(mid*(mid+1)<che) l=mid+1;    
        else if(mid*(mid+1)>che) r=mid-1;
        else return mid;
    }
    return mid;
}
// 1^k+2^k+...+m^k

void printAns(int right,int pow){
    for(int i=1;i<right;i++){
        cout<<i<<"^"<<pow<<"+";
    }
    cout<<right<<"^"<<pow<<endl;
}

int fastpow(int a,int b){
    int ans=1;
    while(b){
        if(b&1) ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n;cin>>n;
    int k = binarysearch(1,n,2*n);
    int flag=0;
    if(k*(k+1)==2*n) flag=1;
    else if(k*(k-1)==2*n) flag=1;
    else {
        cout<<"Impossible for "<<n<<"."<<endl;
        return ;
    }
    int l = 1; int r = k/2+1;
    // cout<<fastpow(2,5)<<endl;

    // cout<<l<<" "<<r<<endl;
    int right=k;
    int anspow=1;
    // printAns(right,anspow);
    int tmp=2;
    while(l<r and r!=0){
        // cout<<l<<" "<<r<<endl;
        int res=1;
        // cout<<res<<endl;
        for(int i=2;i<=r;i++){
    
            res+=pow(i,tmp);
            // cout<<res<<endl;
            if(res>n) break;
            if(res==n) {
                anspow=tmp;
                right=i;
                flag=1;
                break;
            }
        }
        tmp+=1;
        r>>=1;
    }
    if(flag=1){
        printAns(right,anspow);
    }
    else {
        cout<<"Impossible for "<<n<<"."<<endl;
        return ;
    }
}



signed main(){
    solve();
    return 0;
}